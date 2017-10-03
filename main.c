#include <pic16f1619.h>
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/adc.h"
#include "mcc_generated_files/dac1.h"
#include "mcc_generated_files/pwm3.h"
#include "mcc_generated_files/tmr0.h"

int pid_sw_float(int ad);
int pid_sw_fixed(int ad);


int sp = 312;

void MATHACC_LoadK1(uint32_t value) {
    PID1K1L = (0x000000FF & value);
    PID1K1H = ((0x0000FF00 & value) >> 8);
}

void MATHACC_LoadK2(uint32_t value) {
    PID1K2L = (0x000000FF & value);
    PID1K2H = ((0x0000FF00 & value) >> 8);
}

void MATHACC_LoadK3(uint32_t value) {
    PID1K3L = (0x000000FF & value);
    PID1K3H = ((0x0000FF00 & value) >> 8);
}


//intermediate variables
float f_e0 = 0, f_e1 = 0, f_e2 = 0;
float f_y0 = 0, f_y1 = 0;
const float f_kp = 1, f_ki = 100, f_kd = 0;
const float f_T = 0.001;

#define SHIFT (256)
int16_t i_e0 = 0, i_e1 = 0, i_e2 = 0;
int16_t i_y0 = 0, i_y1 = 0;

void main(void) {
    int32_t res;
    int16_t ad;
    int16_t i = 0;
    //1.05
    const int16_t i_k1 = (f_kp + f_ki * f_T + f_kd / f_T) * SHIFT;
    //-1
    const int16_t i_k2 = -((f_kp + 2 * f_kd / f_T) * SHIFT);
    //0
    const int16_t i_k3 = (f_kd / f_T) * SHIFT;
    MATHACCResult temp;

    SYSTEM_Initialize();
    MATHACC_ClearResult();
    IO_RA5_SetLow();
    MATHACC_LoadK1(i_k1);
    MATHACC_LoadK2(i_k2);
    MATHACC_LoadK3(i_k3);

    
    res = 0;
    for (;;) {


        TMR0_Reload();
        i++;
        if (i >= 1000) {
            i = 0;
            if (sp == (712)) {
                sp = (312);
                IO_RC5_SetLow();
                MATHACC_SetReference(312);
            } else {
                IO_RC5_SetHigh();
                sp = (712);
                MATHACC_SetReference(712);
            }
        }
        ad = ADC_GetConversion(channel_AN9);

        //Hardware - 8.17 us
        //SW fixed - 90.69 us
        //SW float - 520.1 us
        IO_RA5_SetHigh();

        res = MATHACC_PIDResult(ad);
        //res = pid_sw_fixed(ad);
        //res = pid_sw_float(ad);

        IO_RA5_SetLow();
        PWM3_LoadDutyValue(res);
        while (!TMR0_HasOverflowOccured());

    }
}


#define MAX_SAT 1023
#define MIN_SAT 0

int16_t pid_sw_float(int16_t ad) {
    const float f_k1 = f_kp + f_ki * f_T + f_kd / f_T;
    const float f_k2 = -(f_kp + 2 * f_kd / f_T);
    const float f_k3 = f_kd / f_T;

    // Update variables
    f_y1 = f_y0;
    f_e2 = f_e1;
    f_e1 = f_e0;
    f_e0 = ((float) sp) - ad;

    // Processing
    //    y0 = (int) y1 + (f_kp * (e0 - e1)) +
    //            (f_ki * (e0) * f_T) +
    //            (f_kd * (e0 - (2 * e1) + e2) / f_T);

    //stated in terms of errors instead of coefficients
    f_y0 = f_y1 + (f_k1 * f_e0) + (f_k2 * f_e1) + (f_k3 * f_e2);

    // Saturation
    if (f_y0 > MAX_SAT) {
        f_y0 = MAX_SAT;
    } else if (f_y0 < MIN_SAT) {
        f_y0 = MIN_SAT;
    }

    return f_y0;
}

int pid_sw_fixed(int ad) {
    const int16_t i_k1 = (f_kp + f_ki * f_T + f_kd / f_T) * SHIFT;
    const int16_t i_k2 = -((f_kp + 2 * f_kd / f_T) * SHIFT);
    const int16_t i_k3 = (f_kd / f_T) * SHIFT;

    // Update variables
    i_y1 = i_y0;
    i_e2 = i_e1;
    i_e1 = i_e0;

    //ad = READ_AD())
    i_e0 = (sp - ad);

    // Processing
    //the multiplication is for a number range in 4.2(6 bits) (gains from zero up to +15.75) 
    // times 0.3ff (10 bits)
    //    y0 = y1 + (i_kp * (e0 - e2)) +
    //            (i_ki * (e0) * i_T) +
    //            (i_kd * (e0 - (2 * e1) + e2) / i_T);
    //stated in terms of errors instead of coefficients
    i_y0 = (((int32_t) i_k1 * i_e0) + ((int32_t) i_k2 * i_e1) + ((int32_t) i_k3 * i_e2));
    i_y0 = i_y0 >> 8;
    i_y0 += i_y1;

    // Saturation
    if (i_y0 > MAX_SAT) {
        i_y0 = MAX_SAT;
    } else if (i_y0 < MIN_SAT) {
        i_y0 = MIN_SAT;
    }

    return i_y0;
}
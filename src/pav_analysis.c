#include <math.h>
#include <stdlib.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N){
    float sum = 0;

    for (int i = 0; i < N; i++){
        sum = sum + x[i]*x[i];
    }

    float power = 10 * log10(sum/N);
    return power;
}

float compute_am(const float *x, unsigned int N){
    float am = 0;

    for(int n = 0; n < N; n++) {
        am += fabs(x[n]);
    }

    return am;
}

float compute_zcr(const float *x, unsigned int N, float fm){
    float sum = 0;

    for (int i = 1; i < N; i++){
        if((x[i]>0 && x[i-1]<0)||(x[i]<0 && x[i-1]>0)){
            sum++;
        }
    }

    float zcr = (fm/2)*(sum/(N-1));
    
    return zcr;
}
/*
float compute_power_ventana(const float *x, const float *w, int i, float fm, unsigned int N){
    float power=compute_power(x,N);
    int i=1;//bloque i-esimo, variante?¿
    int N, M, tlong=0.02, tdesp=0.01;
    float *xi;
    float num=0, den=0;
    N=(fm*tlong)/1;
    M=(fm*tdesp)/1;

    for (int j=1; j<N; j++){
        w[j]=0.54-0.4616*cosinus((2*3.24*j)/(N-1));//calculamos la ventana Hamming manualmente
    }

    for(int j=1; j<N; j++){
        xi[j]=x[i*M+j];
    }
    for(int k=1; k<N; k++){
        num=num+(x[k]*w[k])*(x[k]*w[k]);
        den=den+w[k]*w[k];
    }
    return 10 * log10(num/den);
}
*/

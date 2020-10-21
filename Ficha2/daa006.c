#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool checkDist(double qx,double qy,double qx2,double qy2,double cx,double cy,double cr){
    double centro1 = ((qx-cx)*(qx-cx) + (qy2-cy)*(qy2-cy)); //canto superior esquerdo
    double centro2 = ((qx2-cx)*(qx2-cx) + (qy2-cy)*(qy2-cy)); //canto superior direito
    double centro3 = ((qx-cx)*(qx-cx) + (qy-cy)*(qy-cy)); //canto inferior esquerdo
    double centro4 = ((qx2-cx)*(qx2-cx) + (qy-cy)*(qy-cy)); //canto inferior direito

    if(centro1 <= cr*cr && centro2 <= cr*cr && centro3 <= cr*cr && centro4 <= cr*cr){
        return true;
    }else {
        return false;
        }
}

bool checkLadeits(double qx,double qy,double qx2,double qy2,double cx,double cy,double cr){
    double ladeits1 = cy+cr;
    double ladeits2 = cx+cr;
    double ladeits3 = cy-cr;
    double ladeits4 = cx-cr;
    if(qy2 >= ladeits1 && qx2 >= ladeits2 && qy <= ladeits3 && qx <= ladeits4){
        return true;
    }else{
        return false;
    }
}

double intersecao(double qx,double qy,double qx2,double qy2,double cx,double cy,double cr){
    double closestX = fmaxf(qx,fminf(cx,qx2));
    double closestY = fmaxf(qy,fminf(cy,qy2));

    double distanceX = cx - closestX;
    double distanceY = cy - closestY;

    double ladoquadrado = qx2-qx;
    
    if(ladoquadrado*ladoquadrado < 0.000000000001){
        return ladoquadrado*ladoquadrado;
    }


    if((distanceX * distanceX)+(distanceY * distanceY) >= (cr * cr)){
        return 0;
    }
    if(checkDist(qx,qy,qx2,qy2,cx,cy,cr)){ 
        return ladoquadrado*ladoquadrado;   //quadrado dentro do circulo
    }
    if(checkLadeits(qx,qy,qx2,qy2,cx,cy,cr)){
        return M_PI*cr*cr;    //circulo dentro de quadrado
    } 
    else{
        double area = 0;
        area = area + intersecao(qx,qy + ladoquadrado/2.0,qx2 - ladoquadrado/2.0,qy2,cx,cy,cr); // quadrado superior esquerdo
        area = area + intersecao(qx + ladoquadrado/2.0,qy + ladoquadrado/2.0,qx2,qy2,cx,cy,cr); // quadrado superior direito
        area = area + intersecao(qx,qy,qx2 - ladoquadrado/2.0,qy2 - ladoquadrado/2.0,cx,cy,cr); // quadrado inferior esquerdo
        area = area + intersecao(qx + ladoquadrado/2.0,qy,qx2,qy2 - ladoquadrado/2.0,cx,cy,cr); // quadrado inferior direito    
        return area;   
    }
}

int main(int argc, char const *argv[]){
    int n;
    double qx,qy,ql,cx,cy,cr;
    scanf("%d\n",&n);
    for(double i = 0;i < n; i++){
        scanf("%lf %lf %lf %lf %lf %lf\n",&qx,&qy,&ql,&cx,&cy,&cr);
        double inter = intersecao(qx,qy,qx+ql,qy+ql,cx,cy,cr);
        printf("%.4lf\n", inter);
    }
    return 0;
}

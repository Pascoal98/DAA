#include <stdio.h>
#include <math.h>

double intersecao(double qx, double qy, double ql, double cx, double cy, double cr){
    double closeX = fmax(qx,fmin(cx,qx+ql));
    double closeY = fmax(qy,fmin(cy,qy+ql));
    double distX = cx - closeX;
    double distY = cy - closeY;

    double area = 0;

    if(ql*ql < 0.0000009){
        return ql*ql;
    }

    if((distX*distX)+(distY*distY) >= cr*cr){ //nao se juntam
      return area;
    }
    else if(((cy+cr) <= (qy+ql)) && ((cx+cr) <= (qx+ql)) && ((cy-cr) >= (qy)) && ((cx-cr) >= (qx))){  //circulo dentro do quadrado
        return M_PI*cr*cr;
    }
    else if((qx-cx)*(qx-cx) + (qy-cy)*(qy-cy) < cr*cr  // canto inferior esquerdo
        && (qx+ql-cx)*(qx+ql-cx) + (qy+ql-cy)*(qy+ql-cy) < cr*cr  // canto superior direito
        && (qx-cx)*(qx-cx) + (qy+ql-cy)*(qy+ql-cy) < cr*cr  // canto superior esquerdo
        && (qx+ql-cx)*(qx+ql-cx) + (qy-cy)*(qy-cy) < cr*cr){  //quadrado dentro do circulo
        return ql*ql;
    }
    else{      //recursao
        area += intersecao(qx, qy+ql/2.0, ql/2.0, cx, cy, cr);        //canto superior esquerdo
        area += intersecao(qx+ql/2.0, qy+ql/2.0, ql/2.0, cx, cy, cr);        //canto superior direito
        area += intersecao(qx, qy, ql/2.0, cx, cy, cr);        //canto inferior esquerdo
        area += intersecao(qx+ql/2.0, qy, ql/2.0, cx, cy, cr);        //canto inferior direito
    }
    return area;
}


int main(int argc, char const *argv[]){
    int N;
    double qx, qy, ql, cx, cy, cr;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf %lf %lf %lf %lf %lf", &qx, &qy, &ql, &cx, &cy, &cr);
        printf("%.4lf\n", intersecao(qx, qy, ql, cx, cy, cr));
        
    }
}
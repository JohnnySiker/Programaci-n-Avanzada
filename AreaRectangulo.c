#include <stdio.h>
#include <math.h>

struct Punto{
	int x,y;
};

struct Rectangulo{
	struct Punto a;
	struct Punto b;
};


int areaRectangulo(struct Rectangulo rect){
	if (rect.a.x == rect.b.x || rect.a.y == rect.b.y){
		return NULL;
	}else{
		int area = (rect.a.x - rect.b.x)*(rect.a.y - rect.b.y);
		return sqrt(pow(area,2));	
	}
}

int main(){
	
	struct Rectangulo rect;

	printf("Ingresa el punto A\n");
	printf("x:");
	scanf("%d",&rect.a.x);
	printf("y:");
	scanf("%d",&rect.a.y);

	printf("Ingresa el punto B\n");
	printf("x:");
	scanf("%d",&rect.b.x);
	printf("y:");
	scanf("%d",&rect.b.y);

	printf("A(%d,%d) B(%d,%d)\n", rect.a.x,rect.a.y,rect.b.x,rect.b.y);

	unsigned int area = areaRectangulo(rect);

	if (area == NULL){
		printf("Error no es un rectangulo!!\n");
	}else{
		printf("Area del rectangulo: %d\n",area);
	}
	
	return 0;
}



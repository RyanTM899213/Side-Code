/* CS 3710 - Voc. Langs.
 * Assignment 5
 * Ryan Martin
 * 201039054
 * rtm773
 * Oct. 20/14
 */
 
#include <stdio.h>
#include <string.h>
#include <math.h>
 
// number 1
double sphere_volume(double r) { 

    return (4.0/3.0) * (M_PI * pow(r,3));
}

double sphere_surface(double r) {

    return 4.0 * (M_PI * pow(r,2));
}

double cylinder_volume(double r, double h) {

    return M_PI * (h * pow(r,2));
}

double cylinder_surface(double r, double h) {

    return (2.0 * M_PI * r * h) + (2.0 * M_PI * pow(r,2));
}

// number 2
void printarray(int array[]) {  // prints the array ignoring null characters

    int i;
    for(i = 0; i < sizeof(array); i++) {
    
        if(array[i] != '\0') printf("%d\n",array[i]);
    }    
}

void printintarray(int array[]) {  // prints the array

    int i;
    for(i = 0; i < sizeof(array); i++) {
    
        printf("%d\n",array[i]);  // prints all characters
    }    
}

void remove_minmax(int array[]) {

    int min = array[0];
    int max = array[0];
    int i;
    
    for(i = 1; i < sizeof(array); i++) {
    
        // find smallest and largest values in array
        if (array[i] <= min) min = array[i];
        if (array[i] > max) max = array[i]; 
    }
    for(i = 0; i < sizeof(array); i++) {
    
        if(array[i] == max || array[i] == min) array[i] = '\0';  // set to null
    }
    printarray(array);  // print the array                                       
}

// number 3
void numberthree() {

    int p;
    p = 30;
    p = 6;
    p = p + 5;
    char s[] = "Harry";
    char s2[] = "Tim";
    int a[10];
    int b = 4;
    a[10] = 5;
    int q;
    q = 5;
    q = p;
    p = a[0];
}

// number 4
void sort(int* a, int size) {

	int j;
	
	for(j = 0; j < size; j++) {
	
		int k;
		int smallest;
		
		for(k = j + 1; k < size; k++) {
		
			if(a[k] < a[j]) {
			
				smallest = a[k];
				int temp = a[j];
				a[j] = smallest;
				a[k] = temp;
			}
		}
	}
	int p;
	
	for(p = 0; p < size; p++) {  // print the sorted array
	
		printf("%d\n", a[p]);
	}
}

// main
int main() {

    int radius;
    printf(">> enter radius of sphere: \n");
    scanf("%d", &radius);
    
    printf("sphere volume: %f\n", sphere_volume(radius));
    printf("sphere surface area: %f\n", sphere_surface(radius));
    
    printf(">> enter radius of cylinder: \n");
    scanf("%d", &radius);
    int height;
    printf(">> enter height of cylinder: \n");
    scanf("%d", &height);
    
    printf("cylinder volume: %f\n", cylinder_volume(radius, height));
    printf("cylinder surface area: %f\n", cylinder_surface(radius, height));
    printf("---------------------------\n");
    
    int array[6] = {19, 1, 0, 7, 100, 31};
    printf("array before: \n");
    printintarray(array);
    printf(">> array after: \n");
    remove_minmax(array);
    printf("---------------------------\n");
    
    int array2[7] = {1, 5, 2, 38, 24, 91, 20};
    printf("unsorted array: \n");
    printintarray(array2);
    printf(">> sorted array: \n");
    sort(array2,sizeof(array2));
    return 0;  // required
}

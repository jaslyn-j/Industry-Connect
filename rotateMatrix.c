#include <stdio.h>
#include <stdlib.h>
int main(){
	int i_rows, i_cols, n_col;
 	int **i_arr1;
 	int **i_arr2;
 	int element;
 	printf("Rows: ");
 	scanf("%d", &i_rows);
 	i_arr1=(int**)malloc(i_rows*sizeof(int*));
 	printf("Cols: ");
 	scanf("%d", &i_cols);
 	for(int count=0; count<i_rows; count++){
 		i_arr1[count]=(int*)malloc(i_cols*sizeof(int));
	}
	i_arr2=(int**)malloc(i_rows*sizeof(int*));
	for(int count=0; count<i_rows; count++){
 		i_arr2[count]=(int*)malloc(i_cols*sizeof(int));
	}
	for(int count1=0; count1<i_rows; count1++){
		for(int count2=0; count2<i_cols; count2++){
			printf("Enter element: ");
			scanf("%d", &element);
			i_arr1[count1][count2]=element;
		}
	}
	printf("Original Matrix: \n");
	for(int count1=0; count1<i_rows; count1++){
		for(int count2=0; count2<i_cols; count2++){
			printf("%d ", i_arr1[count1][count2]);
		}printf("\n");
	}
	for(int count1=0; count1<i_cols; count1++){
		for(int count2=0; count2<i_rows; count2++){
			n_col=((i_rows-1)-count1);
			i_arr2[count2][n_col]=i_arr1[count1][count2];
		}
	}printf("90 degree rotated matrix: \n");
	for(int count1=0; count1<i_rows; count1++){
		for(int count2=0; count2<i_cols; count2++){
			printf("%d ", i_arr2[count1][count2]);
		}printf("\n");
	}
	for (int count=0; count<i_rows; count++){
        free(i_arr1[count]);
        free(i_arr2[count]);
    }
    free(i_arr1);
	free(i_arr2);
}


#include <stdlib.h>
#include <stdio.h>


int num_islands(char ** grid, int num_rows, int num_cols);

/* Helper functions */
void dfs(int i,int j,char** grid, int num_rows, int num_cols, int** map);
void display_char_array(char ** grid, int num_rows);
int ** create_int_array(int num_rows, int num_cols, int value);
void destroy_int_array(int ** grid, int num_rows);
void display_int_array(int ** grid, int num_rows, int num_cols);


void main()
{
printf("Grid 1:\n");
char ** grid1 = (char **) malloc(4*sizeof(char *));
grid1[0]  = "11110";
grid1[1]  = "11010";
grid1[2]  = "11000";
grid1[3]  = "00000";
display_char_array(grid1, 4);
printf("Number of islands = %d\n\n", num_islands(grid1,4,5));


printf("Grid 2:\n");
char ** grid2 = (char **) malloc(4*sizeof(char *));
grid2[0]  = "11000";
grid2[1]  = "11000";
grid2[2]  = "00100";
grid2[3]  = "00011";
display_char_array(grid2, 4);
printf("Number of islands = %d\n\n", num_islands(grid2,4,5));


printf("Grid 3:\n");
char ** grid3 = (char **) malloc(8*sizeof(char *));
grid3[0]  = "11000000";
grid3[1]  = "11000011";
grid3[2]  = "00111001";
grid3[3]  = "00001000";
grid3[4]  = "00011100";
grid3[5]  = "01100010";
grid3[6]  = "01101111";
grid3[7]  = "10000100";
display_char_array(grid3, 8);
printf("Number of islands = %d\n\n", num_islands(grid3,8,8));

}
int array[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int num_islands(char ** grid, int num_rows, int num_cols)
{
 int** map = (int**)malloc(num_rows*sizeof(int*));
    for(int i=0; i<num_rows; i++){
        map[i]=(int*)calloc(num_cols,sizeof(int));
    }
    int ret=0;
    for(int i=0; i<num_rows; i++){
        for(int j=0; j<num_cols; j++){
            if(grid[i][j] =='0' || map[i][j] == 1){
                continue;
            }
            ret++;
            map[i][j]=1;
            dfs(i, j, grid, num_rows, num_cols, map);
        }
    }
    return ret;
}

void dfs(int i,int j,char** grid, int num_rows, int num_cols, int** map) {
    for(int k=0; k<4; k++){
        int tempX = i+array[k][0];
        int tempY = j+array[k][1];
        if(tempX >= 0 && tempX < num_rows && tempY >= 0 && tempY < num_cols && map[tempX][tempY] == 0 && grid[tempX][tempY] == '1'){
            map[tempX][tempY] = 1;
            dfs(tempX, tempY, grid, num_rows, num_cols, map);
        }
    }
}


int ** create_int_array(int num_rows, int num_cols, int value)
{
int ** grid = (int **) malloc(num_rows*sizeof(int *));

for (int k=0; k<num_rows; k++) {
    grid[k] = (int *) malloc(num_cols*sizeof(int)); 
}

for (int row=0; row<num_rows; row++) {
    for (int col=0; col<num_cols; col++) {
        grid[row][col] = value;
    }
}

return grid;
}

void destroy_int_array(int ** grid, int num_rows)
{
for (int k=0; k<num_rows; k++) {
    free(grid[k]);
}
free(grid);
}

void display_char_array(char ** grid, int num_rows)
{
for (int k=0; k<num_rows; k++) {
    printf("%s\n", grid[k]);
}
}

void display_int_array(int ** grid, int num_rows, int num_cols)
{
for (int row=0; row<num_rows; row++) {
    for (int col=0; col<num_cols; col++) {
	printf("%d",grid[row][col]);
    }
    printf("\n");
}
}


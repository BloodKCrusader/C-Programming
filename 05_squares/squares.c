#include <stdio.h>
#include <stdlib.h>


/* 
 * Determines if coord is in range between
 * offset (INCLUSIVE) and offset + size (EXCLUSIVE)
 */
int isInRange(int coord, int offset, int size) {
  // if coord is in range, return 1
  if (coord >=  offset && coord < offset + size) {
    return 1;
  }
  // else, return 0
  else {
    return 0;
  }
}

/*
 * Determines if coord is at border of offset or
 * offset + size
 */
int isAtBorder(int coord, int offset, int size) {
  // if coord is equal to offest or offset + size
  if (coord == offset || coord == offset + size - 1) {
  // return 1, else return 0
      return 1;
    }
  else {
    return 0;
  }
}

int a(int coord, int size) {
  if (coord < size) {
    return 1;
  }
  else {
    return 0;
  }
}

int b(int coord, int size) {
  if (coord == 0 || coord == size - 1) {
    return 1;
  }
  else {
    return 0;
  }
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w,h;
  if (size1 > (x_offset + size2)) {
    w = size1;
  }
  else {
    w = x_offset + size2;
  }
  //compute the max of size1 and (y_offset + size2).  Call this h
  if (size1 > (y_offset + size2)) {
    h = size1;
  }
  else {
    h = y_offset + size2;
  }
  //count from 0 to h. Call the number you count with y
  int y,x;
  for (y = 0;y < h; y++) {
    //count from 0 to w. Call the number you count with x
    for (x = 0; x < w; x++) {
      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *
      if ( (isInRange(x,x_offset,size2) && isAtBorder(y,y_offset,size2)) || (isInRange(y,y_offset,size2) && isAtBorder(x,x_offset,size2))) {
	printf ("*");
      }
      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #
      else {
	if (((a(x,size1) && b(y,size1))) || ((a(y,size1) && b(x,size1)))) {
	  printf ("#");
	}
      //else print a space
	else {
	  printf(" ");
	}
      }
    //when you finish counting x from 0 to w, 
    //print a newline
    }
	printf("\n");
  }
}




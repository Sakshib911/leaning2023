/*1. Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.
 b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.*/

#include <stdio.h>

// Define the structure for a box
struct Box {
    float length;
    float width;
    float height;
};

// Function to calculate the volume of the box
float calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

// Function to calculate the total surface area of the box
float calculateSurfaceArea(struct Box* boxPtr) {
    float length = boxPtr->length;
    float width = boxPtr->width;
    float height = boxPtr->height;

    float topBottomArea = length * width;
    float frontBackArea = length * height;
    float leftRightArea = width * height;

    return 2 * (topBottomArea + frontBackArea + leftRightArea);
}

int main() {
    // Declare and initialize a box using a structure variable
    struct Box myBox;
    myBox.length = 5.0;
    myBox.width = 3.0;
    myBox.height = 4.0;

    // Declare a pointer to the box structure
    struct Box* boxPtr = &myBox;

    // Calculate the volume and total surface area using the structure pointer
    float volume = calculateVolume(boxPtr);
    float surfaceArea = calculateSurfaceArea(boxPtr);

    // Print the results
    printf("Volume of the box: %.2f\n", volume);
    printf("Total surface area of the box: %.2f\n", surfaceArea);

    return 0;
}

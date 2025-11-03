int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize){
    int count_zeros = 0;
    int count_ones = 0;
    
    for (int i = 0; i < studentsSize; i++) {
        if (students[i] == 0) {
            count_zeros++;
        } else {
            count_ones++;
        }
    }
    
    for (int i = 0; i < sandwichesSize; i++) {
        if (sandwiches[i] == 0) {
            if (count_zeros > 0) {
                count_zeros--;
            } else {
                break;
            }
        } else {
            if (count_ones > 0) {
                count_ones--;
            } else {
                break;
            }
        }
    }
    
    return count_zeros + count_ones;
}
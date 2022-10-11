#include "sort.h"                                                                                    
                                                                                                     
/**                                                                                                  
 * selection_sort - function that sorts an array of integers in                                      
 * ascending order using the Selection sort algorithm                                                
 * @array: The array to sort                                                                         
 * @size: The size of the array                                                                      
 *                                                                                                   
 * Return: void                                                                                      
 */                                                                                                  
                                                                                                     
void selection_sort(int *array, size_t size)                                                         
{                                                                                                    
        int temp;                                                                                    
        int *min = NULL;                                                                             
        size_t i, j;                                                                                 
                                                                                                     
        if (!array || size == 0)                                                                     
                return;                                                                              
                                                                                                     
        for (i = 0; i < size - 1; i++)                                                               
        {                                                                                            
                min = &array[i];                                                                     
                for (j = i + 1; j < size; j++)                                                       
                {                                                                                    
                        if (*min > array[j])                                                         
                                min = &array[j];                                                     
                }                                                                                    
                if (min != &array[i])                                                                
                {                                                                                    
                        temp = *min;                                                                 
                        *min = array[i];                                                             
                        array[i] = temp;                                                             
                        print_array(array, size);                                                    
                }                                                                                    
        }                                                                                            
}

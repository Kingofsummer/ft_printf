#include "ft_printf.h"
// int ft_function(size_t numb, int base)
// {
//     int i;
//     i = 1;
//     if(base == 0)
//         return(0);

//     while(numb / base)
//     {
//         i++;
//         numb /= base;
//     }
//     printf("%d", i );
//     return(i);
// } 
// int ft_function1(ssize_t numb, int base)
// {
//     int i;
//     i = 1;
//     if(base == 0)
//         return(0);
// 	if(numb < 0)
// 		i++;
//     while(numb / base)
//     {
//         i++;
//         numb /= base
//     }
//     printf("%d", i );
//     return(i);
// } 
int main(void)
{
	char *format;
	// format = "%hhd";
	
	 int i;

	 i = 1;
	setlocale(LC_ALL, "");
	//  printf("%s\n", ft_myitoa_base(i , 10, list));
	// printf("% Zoooo\n");
	// ft_printf("% Zoooo\n");
	printf("|%.4S|\n", L"我是一只猫。");
	ft_printf("|%.4S|\n", L"我是一只猫。");
	
	
	// ft_printf("|%#08x|\n", 42);

	
    //   printf("---------------------------\n");
	// printf("\n");

	//  ft_function1(-123456, 10);
    
	//--------------ширина------------
	// 10 - 7 = 3
	//  виводимо 3 пробела і число
	//--------------точніть----------------
	//
	//
	//--------------флаги------------------
	//
	return(0);
}



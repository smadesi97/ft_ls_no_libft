#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

int main(int argc, char **argv){
    int a = ft_atoi(argv[1]);
    int b = ft_atoi(argv[2]);
    
    if (argc > 1){
        print_numbers(a, b);
    }
    else
    {
        ft_putstr("Error: Sukuphambana apha.");
    }
   return(0); 
}
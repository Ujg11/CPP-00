#include <iostream> //Entrada y salida standard
#include <string> //Manejar cadenas de caracteres std::string
#include <locale> //Configuraciones regionales

int	main(int argc, char **argv)
{
	std::string	s;
	int			i = 1;
	int			j = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{ 
		while (i < argc)
		{
			if (argv[i] && !argv[i][0])
				i++;
			if (argv[i] && argv[i][0])
			{
				s = argv[i];
				while (j < s.length())
				{
					s[j] = toupper(s[j]);
					j++;
				}
				std::cout << s;
				i++;
				j = 0;
			}
		}
	}
	std::cout << std::endl;
	return (0);
}

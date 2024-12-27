#include <stdio.h>

int prompt_get_int(const char * prompt);
double prompt_get_double(const char * prompt);

double cel_to_fah(const double num);
double cel_to_kel(const double num);

double fah_to_cel(const double num);
double fah_to_kel(const double num);

double kel_to_cel(const double num);
double kel_to_fah(const double num);

int main(int argc, char ** argv)
{
    // Variables
    int input_metric = 0;
    int output_metric = 0;
    double input_number = 0;

    while(1)
    {

        // Get Starting Metric For Conversion / Check if user wants to end
        do
        {
            input_metric = prompt_get_int("--Choose input metric--\n1: Celsius\n 2: Fahrenheit\n 3:"
                    "Kelvin\n 4: Close Program\n : ");
        } while (input_metric < 1 || input_metric > 4);

        if (input_metric == 4)
        {
            printf("Closing Program.\n");
            return 0;
        }

        // Get Output Metric For Convserions
        do
        {
            output_metric = prompt_get_int("--Choose output metric--\n1: Celsius\n 2: Fahrenheit\n 3:"
                    "Kelvin\n: ");
        } while (output_metric < 1 || output_metric > 3);

        // Get Number For Convserions
        input_number = prompt_get_double("Enter Number to Convert: ");

        switch (input_metric)
        {
            case 1:
                if (output_metric == 1)
                {
                    double output_number = input_number;
                    printf("Celsius: %lf Converted to Celsius is:"
                           " %lf.\n",input_number, output_number);
                    break;
                }
                else if (output_metric == 2)
                {
                    double output_number = cel_to_fah(input_number);
                    printf("Celsius: %lf Converted to Fahrenheit is: %lf.\n",
                            input_number, output_number);
                    break;
                }
                else if (output_metric == 3)
                {
                    double output_number = cel_to_kel(input_number);
                    printf("Celsius: %lf Converted to Kelvin is: %lf.\n",
                            input_number, output_number);
                    break;
                }
                else
                {
                    printf("IDK HOW YOU GOT HERE BUT IT IS BAD AND AN ERR.\n");
                    return 0;
                }
            case 2:
                if (output_metric == 1)
                {
                    double output_number = fah_to_cel(input_number);
                    printf("Fahrenheit: %lf Converted to Celsius is:"
                           " %lf.\n",input_number, output_number);
                    break;
                }
                else if (output_metric == 2)
                {
                    double output_number = input_number;
                    printf("Fahrenheit: %lf Converted to Fahrenheit is: %lf.\n",
                            input_number, output_number);
                    break;
                }
                else if (output_metric == 3)
                {
                    double output_number = fah_to_kel(input_number);
                    printf("Fahrenheit: %lf Converted to Kelvin is: %lf.\n",
                            input_number, output_number);
                    break;
                }
                else
                {
                    printf("IDK HOW YOU GOT HERE BUT IT IS BAD AND AN ERR.\n");
                    return 0;
                }
            case 3:
                if (output_metric == 1)
                {
                    double output_number = kel_to_cel(input_number);
                    printf("Kelvin: %lf Converted to Celsius is:"
                           " %lf.\n",input_number, output_number);
                    break;
                }
                else if (output_metric == 2)
                {
                    double output_number = kel_to_fah(input_number);
                    printf("Kelvin: %lf Converted to Fahrenheit is: %lf.\n",
                            input_number, output_number);
                    break;
                }
                else if (output_metric == 3)
                {
                    double output_number = input_number;
                    printf("Kelvin: %lf Converted to Kelvin is: %lf.\n",
                            input_number, output_number);
                    break;
                }
                else
                {
                    printf("IDK HOW YOU GOT HERE BUT IT IS BAD AND AN ERR.\n");
                    return 0;
                }
            }
        }
}

int prompt_get_int(const char * prompt)
{
        int ret = 0;

        printf("%s", prompt);
        while (scanf("%d", &ret) != 1)
        {
            while (getchar() != '\n');
            printf("%s", prompt);
        }

        return ret;
}

double prompt_get_double(const char * prompt)
{
        double ret = 0;

        printf("%s", prompt);
        while (scanf("%lf", &ret) != 1)
        {
            while (getchar() != '\n');
            printf("%s", prompt);
        }

        return ret;
}

double cel_to_fah(const double num)
{
    return (num * 9.0/5.0) + 32;
}

double cel_to_kel(const double num)
{
    return num + 273.15;
}

double fah_to_cel(const double num)
{
    return (num - 32) * (5.0/9.0);
}

double fah_to_kel(const double num)
{
    return (num - 32) * 5.0/9.0 + 273.15;
}

double kel_to_cel(const double num)
{
    return num - 273.15;
}

double kel_to_fah(const double num)
{
    return (num - 273.15) * 1.8 + 32;
}


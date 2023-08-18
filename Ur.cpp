#include"TXLib.h"
#include<math.h>
#include<float.h>
#define SIZES 3
void inputf(double coefficients[]); //ôóíêöèÿ ââîäà êîýôôèöåíòîâ
double computation_discriminant(double coefficients[]); //ôóíêöèÿ íàõîæäåíèÿ äèñêðèìèíàíòà
int main(void)
{
    double discriminant;
    double coefficients[SIZES]; // â ìàññèâ ïîñòóïàþò êîýôôèöåíòû êâàäðàòíîãî óðàâíåíèÿ
    coefficients[1] = coefficients[2] = coefficients[3] = 0;
    inputf(coefficients);
    double a = coefficients[0], b = coefficients[1], x_1, x_2;
    discriminant = computation_discriminant(coefficients);
    if (discriminant < 0)
        printf("Äåéñòâèòåëüíûõ êîðíåé íåò!\n");
    else if (fabs(discriminant) < 0.000001)
    {
        x_1 = -b/(2*a);
        printf("Êîðåíü êâàäðàòíîãî óðàâíåíèÿ: %g\n", x_1);
    }
    else
    {
        x_1 = (-b - sqrt(discriminant))/(2 * a);
        x_2 = (-b + sqrt(discriminant))/(2 * a);
        printf("Êîðíè êâàäðàòíîãî óðàâíåíèÿ: %g è %g\n", x_1, x_2);
    }
    return 0;
}
void inputf(double coefficients[])
{
    int el, i;
    printf("Ââåäèòå êîýôôèöåíòû êâàäðàòíîãî óðàâíåíèÿ âèäà: A*x^2+B*x+C = 0\n");
    printf("Êîýôôèöåíòàìè ìîãóò áûòü ÷èñëà ñ ïëàâàþùåé òî÷êîé, äëÿ îòäåëåíèÿ äðîáíîé ÷àñòè èñïîëüçóéòå \".\"\n");
    printf("Ïðèìåð êîýôôèöåíòîâ: 121 èëè 567.7 \n");
    do
    {
        for (i = 0; i < 3; i++)
        {
            do
            {
                printf("Ââåäèòå êîýôôèöåíò %c = ", 'A' + i);
                scanf("%lf", &coefficients[i]);
                if ((el = getchar()) != '\n')
                {
                    printf("ÎØÈÁÊÀ! Îáíàðóæåí ñèìâîë \"%c\", êîòîðûé ïðîãðàììà íå ìîæåò ñ÷èòàòü!\n", el);
                    printf("Âîçìîæíî êîýôôèöåíò ñîõðàí¸í íåâåðíî, ïðîâåðüòå ïðàâèëüíîñòü ââîäà!\n");
                    while((el = getchar()) != '\n')
                        continue;
                }
                printf("Êîýôôèöåíò %c = %f\n", 'A' + i, coefficients[i]);
                do
                {
                    if (fabs(coefficients[i]) < 0.000001 && i == 0)
                    {
                        printf("ÎØÈÁÊÀ! Çíà÷åíèå êîýôôèöåíòà A äîëæíî áûòü íåíóëåâûì ÷èñëîì, ââåäèòå åãî åù¸ ðàç!\n");
                        break;
                    }
                    if (fabs(coefficients[i]) > FLT_MAX)
                    {
                        printf("ÎØÈÁÊÀ! Çíà÷åíèå êîýôôèöåíòà %c äîëæíî áûòü ìåíüøå %g ïî àáñîëþòíîé âåëè÷èíå.", 'A' + i, FLT_MAX);
                        break;
                    }
                    printf("Eñëè âû ñîãëàñíû ñ ââåä¸ííûìè äàííûìè, íàæìèòå <y>\n");
                    printf("Åñëè âû õîòèòå ââåñòè äàííûå åù¸ ðàç, íàæìèòå <n>\n");
                }while ((el = getch()) != 'y' && el != 'n');
            }while(el != 'y');
        }
        printf("Êâàäðàòíîå óðàâíåíèå: %g*X^2%+g*X%+g = 0\n", coefficients[0], coefficients[1], coefficients[2]);
        do
        {
            printf("Eñëè âû ñîãëàñíû ñ ââåä¸ííûìè äàííûìè, íàæìèòå <y>\n");
            printf("Åñëè âû õîòèòå ââåñòè äàííûå åù¸ ðàç, íàæìèòå <n>\n");
        }while ((el = getch()) != 'y' && el != 'n');
    }while(el != 'y');
}
double computation_discriminant(double coefficients[])
{
    double a = coefficients[0], b = coefficients[1], c = coefficients[2], discriminant;
    discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return -1.0;
    else
        return discriminant;
}

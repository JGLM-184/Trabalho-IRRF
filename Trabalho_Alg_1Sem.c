#include<stdio.h>
#include<locale.h>

void main()
{
    //DECLARAÇÃO DE VARIÁVEIS
    float CPF, Sal_Bruto;
    int Depend;

    float Desc_Depend, Desc_INSS, Valor_Depend=189.59;
    float Sal_Base, Aliquota, Deducao;

    float Desc_IRRF, Sal_Liquido;
    float Aliquota2, Deducao2;

    //ACENTUAÇÃO GRÁFICA EM PT-BR
    setlocale(LC_ALL,"Portuguese");

    printf("       CÁLCULO DE IRRF\n\n");

    //ENTRADA DE DADOS
    printf("Digite seu CPF (sem ponto e traço): ");
     scanf("%f",&CPF);
    printf("\nDigite o número de dependentes: ");
     scanf("%d",&Depend);
    printf("\nDigite a sua renda mensal: R$");
     scanf("%f",&Sal_Bruto);

     //CÁLCULO DO DESCONTO DE DEPENDENTES
     Desc_Depend = (Depend * Valor_Depend);

     //CÁLCULO PARA VALOR DO DESCONTO DE INSS (ALÍQUOTA E DEDUÇÃO)
    if(Sal_Bruto<=1302)
     {
      Aliquota = 0.075;
      Deducao = 0;
     }

    if(Sal_Bruto >= 1302.01 && Sal_Bruto <= 2571.29)
     {
      Aliquota = 0.09 ;
      Deducao = 19.53 ;
     }

    if(Sal_Bruto >= 2571.30 && Sal_Bruto <= 3856.94)
      {
       Aliquota = 0.12 ;
       Deducao = 96.67;
      }

    if(Sal_Bruto >= 3856.95 && Sal_Bruto <= 7507.49)
      {
       Aliquota = 0.14;
       Deducao = 173.80;
      }

    if(Sal_Bruto > 7507.49)
      {
       Aliquota = 1;
       Deducao = 877.22;
      }

      //CÁLCULO DE DESCONTO DO INSS
      Desc_INSS = (Sal_Bruto * Aliquota) - Deducao;
      Sal_Base = Sal_Bruto - (Desc_INSS + Desc_Depend);

      //CÁLCULO FINAL DO DESCONTO DO INSS COM BASE NO CÁLCULO ANTERIOR
      //(ALÍQUOTA E PARCELA A DEDUZIR DO IRRF)
      if(Sal_Base <= 1903.98)
       {
        Aliquota2 = 0 ;
        Deducao2 = 0 ;
       }

      if(Sal_Base >= 1903.99 && Sal_Base <= 2826.65)
       {
        Aliquota2 = 0.075 ;
        Deducao2 = 142.80 ;
       }

      if(Sal_Base >= 2826.66 && Sal_Base <=  3751.05)
       {
        Aliquota2 = 0.15;
        Deducao2 = 354.80;
       }

      if(Sal_Base >=  3751.06 && Sal_Base <= 4664.68)
       {
        Aliquota2 = 0.225;
        Deducao2 = 636.13;
       }

      if(Sal_Base > 4664.68)
       {
        Aliquota2 = 0.275;
        Deducao2 = 869.36;
       }

      //CÁLCULO FINAL DO IRRF
      Desc_IRRF = (Sal_Base * Aliquota2) - Deducao2;
      Sal_Liquido = Sal_Bruto - (Desc_INSS + Desc_IRRF);

      //MENSAGENS FINAIS
      printf("\n\nO valor do seu IRRF descontado mensalmente é: R$%.2f\n",Desc_IRRF);
      printf("\n\nO valor do seu INSS descontado mensalmente é: R$%.2f\n",Desc_INSS);
      printf("\n\nO valor do seu salário líquido é: R$%.2f\n",Sal_Liquido);
}

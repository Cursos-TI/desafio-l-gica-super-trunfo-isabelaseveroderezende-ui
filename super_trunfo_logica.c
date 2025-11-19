#include <stdio.h>
#include <string.h>

int main() {
    // Variáveis para o Código A01
    char nome_estado_A01[50];
    char nome_cidade_A01[50];
    long long populacao_A01;
    double area_A01, pib_A01, densidade_A01, pib_per_capita_A01, super_poder_A01;
    int pontos_turisticos_A01;

    // Variáveis para o Código A02
    char nome_estado_A02[50];
    char nome_cidade_A02[50];
    long long populacao_A02;
    double area_A02, pib_A02, densidade_A02, pib_per_capita_A02, super_poder_A02;
    int pontos_turisticos_A02;

    // Variáveis para o Código B01
    char nome_estado_B01[50];
    char nome_cidade_B01[50];
    long long populacao_B01;
    double area_B01, pib_B01, densidade_B01, pib_per_capita_B01, super_poder_B01;
    int pontos_turisticos_B01;

    // Variáveis para o Código B02
    char nome_estado_B02[50];
    char nome_cidade_B02[50];
    long long populacao_B02;
    double area_B02, pib_B02, densidade_B02, pib_per_capita_B02, super_poder_B02;
    int pontos_turisticos_B02;

    // Variáveis temporárias para as cartas selecionadas
    char nome_estado1[50], nome_cidade1[50], codigo1[4];
    char nome_estado2[50], nome_cidade2[50], codigo2[4];
    long long pop1, pop2;
    double area1, area2, pib1, pib2, dens1, dens2, pibpc1, pibpc2;
    int pontos1, pontos2;
    double soma1, soma2;
    int atributo1, atributo2;
    char continuar[10];
    int rodada = 1;

    printf("=== CADASTRO DE CARTAS - SUPER TRUNFO PAÍSES ===\n");

    // Cadastro do Código A01
    printf("\nDados para A01:\n");
    printf("Nome do Estado: ");
    scanf("%s", nome_estado_A01);
    printf("Nome da Cidade: ");
    scanf("%s", nome_cidade_A01);
    printf("População: ");
    scanf("%lld", &populacao_A01);
    printf("Área (km²): ");
    scanf("%lf", &area_A01);
    printf("PIB: ");
    scanf("%lf", &pib_A01);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos_A01);
    if (area_A01 > 0)
        densidade_A01 = (double) populacao_A01 / area_A01;
    else
        densidade_A01 = 0.0;
    if (populacao_A01 > 0)
        pib_per_capita_A01 = pib_A01 / (double) populacao_A01;
    else
        pib_per_capita_A01 = 0.0;
    super_poder_A01 =
        (double) populacao_A01 +
        area_A01 +
        pib_A01 +
        pontos_turisticos_A01 +
        densidade_A01 +
        pib_per_capita_A01;

    // Cadastro do Código A02
    printf("\nDados para A02:\n");
    printf("Nome do Estado: ");
    scanf("%s", nome_estado_A02);
    printf("Nome da Cidade: ");
    scanf("%s", nome_cidade_A02);
    printf("População: ");
    scanf("%lld", &populacao_A02);
    printf("Área (km²): ");
    scanf("%lf", &area_A02);
    printf("PIB: ");
    scanf("%lf", &pib_A02);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos_A02);
    if (area_A02 > 0)
        densidade_A02 = (double) populacao_A02 / area_A02;
    else
        densidade_A02 = 0.0;
    if (populacao_A02 > 0)
        pib_per_capita_A02 = pib_A02 / (double) populacao_A02;
    else
        pib_per_capita_A02 = 0.0;
    super_poder_A02 =
        (double) populacao_A02 +
        area_A02 +
        pib_A02 +
        pontos_turisticos_A02 +
        densidade_A02 +
        pib_per_capita_A02;

    // Cadastro do Código B01
    printf("\nDados para B01:\n");
    printf("Nome do Estado: ");
    scanf("%s", nome_estado_B01);
    printf("Nome da Cidade: ");
    scanf("%s31", nome_cidade_B01);
    printf("População: ");
    scanf("%lld", &populacao_B01);
    printf("Área (km²): ");
    scanf("%lf", &area_B01);
    printf("PIB: ");
    scanf("%lf", &pib_B01);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos_B01);
    if (area_B01 > 0)
        densidade_B01 = (double) populacao_B01 / area_B01;
    else
        densidade_B01 = 0.0;
    if (populacao_B01 > 0)
        pib_per_capita_B01 = pib_B01 / (double) populacao_B01;
    else
        pib_per_capita_B01 = 0.0;
    super_poder_B01 =
        (double) populacao_B01 +
        area_B01 +
        pib_B01 +
        pontos_turisticos_B01 +
        densidade_B01 +
        pib_per_capita_B01;

    // Cadastro do Código B02
    printf("\nDados para B02:\n");
    printf("Nome do Estado: ");
    scanf("%s", nome_estado_B02);
    printf("Nome da Cidade: ");
    scanf("%s", nome_cidade_B02);
    printf("População: ");
    scanf("%lld", &populacao_B02);
    printf("Área (km²): ");
    scanf("%lf", &area_B02);
    printf("PIB: ");
    scanf("%lf", &pib_B02);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos_B02);
    if (area_B02 > 0)
        densidade_B02 = (double) populacao_B02 / area_B02;
    else
        densidade_B02 = 0.0;
    if (populacao_B02 > 0)
        pib_per_capita_B02 = pib_B02 / (double) populacao_B02;
    else
        pib_per_capita_B02 = 0.0;
    super_poder_B02 =
        (double) populacao_B02 +
        area_B02 +
        pib_B02 +
        pontos_turisticos_B02 +
        densidade_B02 +
        pib_per_capita_B02;

    // Exibição de todos os dados cadastrados
    printf("\n=== DADOS CADASTRADOS ===\n");

    printf("\nCódigo: A01\n");
    printf("Estado: %s\n", nome_estado_A01);
    printf("Cidade: %s\n", nome_cidade_A01);
    printf("População: %lld\n", populacao_A01);
    printf("Área: %.2f km²\n", area_A01);
    printf("PIB: %.2f\n", pib_A01);
    printf("Pontos Turísticos: %d\n", pontos_turisticos_A01);
    printf("Densidade Populacional: %.2f\n", densidade_A01);
    printf("PIB per Capita: %.2f\n", pib_per_capita_A01);
    printf("Super Poder: %.2f\n", super_poder_A01);
    printf("------------------------\n");

    printf("\nCódigo: A02\n");
    printf("Estado: %s\n", nome_estado_A02);
    printf("Cidade: %s\n", nome_cidade_A02);
    printf("População: %lld\n", populacao_A02);
    printf("Área: %.2f km²\n", area_A02);
    printf("PIB: %.2f\n", pib_A02);
    printf("Pontos Turísticos: %d\n", pontos_turisticos_A02);
    printf("Densidade Populacional: %.2f\n", densidade_A02);
    printf("PIB per Capita: %.2f\n", pib_per_capita_A02);
    printf("Super Poder: %.2f\n", super_poder_A02);
    printf("------------------------\n");

    printf("\nCódigo: B01\n");
    printf("Estado: %s\n", nome_estado_B01);
    printf("Cidade: %s\n", nome_cidade_B01);
    printf("População: %lld\n", populacao_B01);
    printf("Área: %.2f km²\n", area_B01);
    printf("PIB: %.2f\n", pib_B01);
    printf("Pontos Turísticos: %d\n", pontos_turisticos_B01);
    printf("Densidade Populacional: %.2f\n", densidade_B01);
    printf("PIB per Capita: %.2f\n", pib_per_capita_B01);
    printf("Super Poder: %.2f\n", super_poder_B01);
    printf("------------------------\n");

    printf("\nCódigo: B02\n");
    printf("Estado: %s\n", nome_estado_B02);
    printf("Cidade: %s\n", nome_cidade_B02);
    printf("População: %lld\n", populacao_B02);
    printf("Área: %.2f km²\n", area_B02);
    printf("PIB: %.2f\n", pib_B02);
    printf("Pontos Turísticos: %d\n", pontos_turisticos_B02);
    printf("Densidade Populacional: %.2f\n", densidade_B02);
    printf("PIB per Capita: %.2f\n", pib_per_capita_B02);
    printf("Super Poder: %.2f\n", super_poder_B02);
    printf("------------------------\n");

    // === INÍCIO DO NÍVEL MESTRE: COMPARAÇÕES AVANÇADAS ===
    while (1) {
        printf("\n=== COMPARAÇÕES AVANÇADAS - NÍVEL MESTRE (Rodada %d) ===\n", rodada);

        // Seleção das duas cartas via código (interativo)
        printf("Digite o código da primeira carta (ex: A01): ");
        scanf("%s", codigo1);
        printf("Digite o código da segunda carta (ex: B02): ");
        scanf("%s", codigo2);

        // Atribuição para carta 1
        if (codigo1[0] == 'A' && codigo1[1] == '0' && codigo1[2] == '1') {
            strcpy(nome_estado1, nome_estado_A01);
            strcpy(nome_cidade1, nome_cidade_A01);
            pop1 = populacao_A01; area1 = area_A01; pib1 = pib_A01; dens1 = densidade_A01;
            pibpc1 = pib_per_capita_A01; pontos1 = pontos_turisticos_A01;
        } else if (codigo1[0] == 'A' && codigo1[1] == '0' && codigo1[2] == '2') {
            strcpy(nome_estado1, nome_estado_A02);
            strcpy(nome_cidade1, nome_cidade_A02);
            pop1 = populacao_A02; area1 = area_A02; pib1 = pib_A02; dens1 = densidade_A02;
            pibpc1 = pib_per_capita_A02; pontos1 = pontos_turisticos_A02;
        } else if (codigo1[0] == 'B' && codigo1[1] == '0' && codigo1[2] == '1') {
            strcpy(nome_estado1, nome_estado_B01);
            strcpy(nome_cidade1, nome_cidade_B01);
            pop1 = populacao_B01; area1 = area_B01; pib1 = pib_B01; dens1 = densidade_B01;
            pibpc1 = pib_per_capita_B01; pontos1 = pontos_turisticos_B01;
        } else if (codigo1[0] == 'B' && codigo1[1] == '0' && codigo1[2] == '2') {
            strcpy(nome_estado1, nome_estado_B02);
            strcpy(nome_cidade1, nome_cidade_B02);
            pop1 = populacao_B02; area1 = area_B02; pib1 = pib_B02; dens1 = densidade_B02;
            pibpc1 = pib_per_capita_B02; pontos1 = pontos_turisticos_B02;
        } else {
            printf("Erro: Carta %s não encontrada!\n", codigo1);
            
        }

        // Atribuição para carta 2
        if (codigo2[0] == 'A' && codigo2[1] == '0' && codigo2[2] == '1') {
            strcpy(nome_estado2, nome_estado_A01);
            strcpy(nome_cidade2, nome_cidade_A01);
            pop2 = populacao_A01; area2 = area_A01; pib2 = pib_A01; dens2 = densidade_A01;
            pibpc2 = pib_per_capita_A01; pontos2 = pontos_turisticos_A01;
        } else if (codigo2[0] == 'A' && codigo2[1] == '0' && codigo2[2] == '2') {
            strcpy(nome_estado2, nome_estado_A02);
            strcpy(nome_cidade2, nome_cidade_A02);
            pop2 = populacao_A02; area2 = area_A02; pib2 = pib_A02; dens2 = densidade_A02;
            pibpc2 = pib_per_capita_A02; pontos2 = pontos_turisticos_A02;
        } else if (codigo2[0] == 'B' && codigo2[1] == '0' && codigo2[2] == '1') {
            strcpy(nome_estado2, nome_estado_B01);
            strcpy(nome_cidade2, nome_cidade_B01);
            pop2 = populacao_B01; area2 = area_B01; pib2 = pib_B01; dens2 = densidade_B01;
            pibpc2 = pib_per_capita_B01; pontos2 = pontos_turisticos_B01;
        } else if (codigo2[0] == 'B' && codigo2[1] == '0' && codigo2[2] == '2') {
            strcpy(nome_estado2, nome_estado_B02);
            strcpy(nome_cidade2, nome_cidade_B02);
            pop2 = populacao_B02; area2 = area_B02; pib2 = pib_B02; dens2 = densidade_B02;
            pibpc2 = pib_per_capita_B02; pontos2 = pontos_turisticos_B02;
        } else {
            printf("Erro: Carta %s não encontrada!\n", codigo2);
            
        }


        // Menu para escolher o primeiro atributo
        printf("\nEscolha o primeiro atributo para comparação:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 6){
            printf("Opção Inválida! Usando população como padrão.");
            atributo1 = 1;
        }

        // Menu dinâmica para o segundo atributo

        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        int operacao = 0, escolha, temp;

        if (atributo1 != 1) printf("%d - População\n", ++operacao);
        if (atributo1 != 2) printf("%d - Área\n", ++operacao);
        if (atributo1 != 3) printf("%d - PIB\n", ++operacao);
        if (atributo1 != 4) printf("%d - Pontos Turísticos\n", ++operacao);
        if (atributo1 != 5) printf("%d - Densidade Populacional\n", ++operacao);
        if (atributo1 != 6) printf("%d - PIB per Capita\n", ++operacao);

        printf("Escolha uma Opção: ");
        scanf("%d", &escolha);
        temp = 0;
        atributo2 = 0;
      

        for (int a = 1; a <= 6; a++){
           if (a != atributo1){
            temp++;
            if (temp == escolha){
                atributo2 = a;
                break;
            }
           } 
        }
        if (atributo2 == 0){
            printf("Opção Inválida! Usando o próximo disponível.\n");
            atributo2 = (atributo1 % 6);
        }


        // Cálculo da soma dos Atributos

        double v1_c1 = 0, v1_c2 = 0, v2_c1 = 0, v2_c2 = 0; 

        // Switch-Case para o primeiro atributo 
        switch (atributo1){ 
        case 1:
            v1_c1 = (double) pop1;
            v1_c2 = (double) pop2;
            break;

        case 2:
            v1_c1 = (double) area1;
            v1_c2 = (double) area2;
            break;
        case 3:
            v1_c1 = (double) pib1;
            v1_c2 = (double) pib2;
            break;
        case 4:
            v1_c1 = (double) pontos1;
            v1_c2 = (double) pontos2;
            break;
        case 5:
            v1_c1 = (double) dens1;
            v1_c2 = (double) dens2;
            break;
        case 6:
            v1_c1 = (double) pibpc1;
            v1_c2 = (double) pibpc2;
            break;
    
        }

        // Switch-Case para o segundo atributo 
        switch (atributo2){
        case 1:
            v2_c1 = (double) pop1;
            v2_c2 = (double) pop2;
            break;

        case 2:
            v2_c1 = (double) area1;
            v2_c2 = (double) area2;
            break;
        case 3:
            v2_c1 = (double) pib1;
            v2_c2 = (double) pib2;
            break;
        case 4:
            v2_c1 = (double) pontos1;
            v2_c2 = (double) pontos2;
            break;
        case 5:
            v2_c1 = (double) dens1;
            v2_c2 = (double) dens2;
            break;
        case 6:
            v2_c1 = (double) pibpc1;
            v2_c2 = (double) pibpc2;
            break;
        }


        soma1 = v1_c1 + v2_c1;
        soma2 = v1_c2 + v2_c2;


        printf("\n===== RESULTADO DA COMPARAÇÃO ===== \n");
        printf("Nome das Cidades:\n");

        printf("- Código 1: %s - %s (%s)\n", codigo1, nome_cidade1, nome_estado1);
        printf("- Código 2: %s - %s (%s)\n", codigo2, nome_cidade2, nome_estado2);  


        printf("\nSoma dos Atributos:\n");
        printf("- Código 1 (%s - %s): %.2f\n", codigo1, nome_cidade1, soma1);
        printf("- Código 2 (%s - %s): %.2f\n", codigo2, nome_cidade2, soma2); 

        if (soma1 > soma2){
            printf("\nResultado: Código 1 (%s - %s) Venceu!!\n", codigo1, nome_cidade1);
        }else if(soma1 < soma2){
            printf("\nResultado: Código 2 (%s - %s) Venceu!!\n", codigo2, nome_cidade2);
        }else{
            printf("\nResultado: Empate!!\n");
        }


        printf("\nDeseja continuar? \"Sim\" para CONTINUAR ou \"Nao\" para SAIR: \n\n");
        scanf("%s", continuar);

        // Aceita "Sim", "sim", "SIM", "S", "s" etc. como continuar
        if (continuar[0] == 'n' || continuar[0] == 'N' || continuar[0] == '0') {
            printf("============================================\n");
            printf("===== Fim do jogo! Obrigado por jogar. =====\n");
            printf("============================================\n");
            break;
        }
        rodada++;
    }

    return 0;
}
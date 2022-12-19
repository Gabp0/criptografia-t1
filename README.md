# RGPS - Trabalho 1 de Criptografia
## Feito por Gabriel Pontarolo e Rodrigo Soffner

### Compilação e execução:

**É necessária a instalação da biblioteca GMP (https://gmplib.org/)**

* Comando **make** faz a compilação dos fontes
* **./rgps [-k chave] [-d] [-c]**
  * **-k** indica a chave para criptografia. Consiste de uma palavra composta de letras/números/símbolos de no mínimo 3 caracteres. Caso não especificada, a chave padrão utilizada é *nerfthis*;
  * **-d** faz a descriptografia do texto cifrado;
  * **-c** faz a criptografia do texto claro;
  * A entrada do texto é feita pela entrada padrão **stdin** e a saída pela saída padrão **stdout**
  * O algoritmo trabalha apenas com os caracteres entre *32* e *126* da tabela *ASCII*. Outros caracteres serão substituídos por *'X'*;

## Sobre:

* Cifra de substituição composta por duas etapas executadas em sequência:

### SBCS314

* Separa o texto claro em blocos de até 128 byts e executa 16 rodadas dividas em duas partes:
  * Cada caracter do texto é passado por uma caixa de substituição construída a partir da **chave** e um campo finito de tamanho 95 que representa os caracteres entre as posições 32 e 126 da tabela *ASCII*. A chave é posicionada antes do inicio da tabela, são retiradas as repetições e então cada símbolo é mapeado no seu inverso multiplicativo dentro do campo finito.
    * **Exemplo**:
        A primeira linha da tabela representa o caracter de entrada na tabela, a segunda o valor **w** atribuido ao caracter, a terceira o inverso multiplicativo **w¹** dentro do GF(95), ou seja, **((w \* w¹) mod 96) == 1** (os valores que não possuem inverso dentro do campo foram mapeados para eles mesmos), e a quarta o caracter resultante. 

        | n | e | r  | f  | t  | h | i  | s  |    | !  | "  | #  | $  | ... | {  | \| | }  | ~  |
        |---|---|----|----|----|---|----|----|----|----|----|----|----|-----|----|----|----|----|
        | 0 | 1 | 2  | 3  | 4  | 5 | 6  | 7  | 8  | 9  | 10 | 11 | 12 | ... | 91 | 92 | 93 | 94 |
        | 0 | 1 | 48 | 32 | 24 | 5 | 16 | 68 | 12 | 74 | 10 | 26 | 8  | ... | 71 | 63 | 47 | 94 |
        | n | e | H  | 8  | 0  | h | (  | \  | $  | b  | "  | 2  |    | ... | _  | W  | G  | ~  |
  * Após isso, a **chave** é convertida em um inteiro utilizando o valor do caracter: *nerfthis* -> *{110, 101, 114, 102, 116, 104, 105, 115}* -> *110101114102116104105115*, e os primeiros 7 digitos são selecionados: 1101011. 
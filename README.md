# Simulador-de-Preditor-de-Desvio-Dinamico-com-Dois-Bits

## Trabalho feito à disciplina de "Organização e Arquitetura de Computadores - 2020".

Consiste em um simulador simples usando como ideia principal a máquina de estados do preditor de desvio dinâmico de dois bits.
Gera aleatoriamente um desvio tomado ou não tomado. Altera o palpite "Guess" de acordo com o erro ou acerto da previsão. 
Seguindo a ideia principal do preditor, internamente ele é apenas um contador que satura nas bordas, ou seja, quando chega no estado máximo ou no estado mínimo não sai.

Para gerar o executável, use o comando make.

Pressione S minusculo ou maiusculo para sair da simulação, I para modificar o estado inicial e qualquer outra tecla para modificar os estados.

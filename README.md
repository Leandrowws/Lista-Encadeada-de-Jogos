Questão: Lista Encadeada com Arquivo

Implemente, em linguagem C, um programa para gerenciar uma lista de jogos eletrônicos utilizando lista encadeada dinâmica.

Cada jogo deve conter as seguintes informações:

Nome (string de até 25 caracteres)
Nota de jogabilidade (0 a 100)
Nota de história (0 a 100)
Nota de arte (0 a 100)
Nota final (float), calculada pela fórmula:
nota = (jogabilidade * 5 + historia * 3 + arte * 2) / 10


Requisitos:
Crie uma estrutura para representar o jogo.
Implemente uma função para inicializar a lista.
Implemente uma função para inserir um novo jogo na lista de forma ordenada, considerando a nota final em ordem decrescente.
Implemente uma função para imprimir todos os jogos da lista, exibindo:
posição - nome (nota final)
Implemente uma função para salvar os dados da lista em um arquivo texto, seguindo um formato estruturado.
Implemente uma função para ler os dados do arquivo e reconstruir a lista encadeada.

O programa deve apresentar um menu com as opções:
Ler dados do arquivo
Imprimir lista
Salvar em arquivo
Inserir novo jogo
Sair

Observações:
Utilize alocação dinâmica de memória (malloc).
Garanta que a leitura do arquivo funcione corretamente mesmo com nomes contendo espaços.
O formato do arquivo deve permitir leitura confiável dos dados (ex: uso de delimitadores).

### ft_print_comb2.c
O que faz: imprime todas as combinacoes de dois numeros de
  dois digitos (00..99), com o primeiro sempre menor.
Como faz: dois lacos. a vai de 0 a 98; b vai de a+1 a 99. Para
  cada par, imprime a, espaco e b com dois digitos. Evita
  virgula no ultimo par.
Entrada/Saida: sem entrada. Saida: "00 01, 00 02, ... 98 99".
Cuidados: nao imprimir virgula apos "98 99". Sempre 2 digitos.

*pseudo codigo*
```txt
início
  definir a como 0
  enquanto a <= 98
    definir b como a + 1
    enquanto b <= 99
      imprimir a com 2 dígitos
      imprimir espaço
      imprimir b com 2 dígitos
      se não for a última combinação
        imprimir ", "
      incrementar b
    incrementar a
fim
```
*processo*
```txt
entrada: sem entrada
passo 1: a=0, b=1 → imprime "00 01"
passo 2: b sobe: ... "00 98", "00 99"
passo 3: a sobe: a=1, b=2 → "01 02" ... "01 99"
passo 4: repete até a=98, b=99
fim: última saída é "98 99"
```
### ft_strlen.c
O que faz: retorna o tamanho da string (sem contar '\0').
Como faz: percorre a partir de str[0] e conta ate encontrar
  o terminador '\0'.
Entrada/Saida: recebe char *str; retorna int com a quantidade
  de caracteres.
Cuidados: string vazia retorna 0. Nao ler alem de '\0'.

*pseudo codigo*
```txt
início
  definir i como 0
  enquanto caractere na posição i não for '\0'
    incrementar i
retornar i
fim
```
*processo*
```txt
entrada: "Hello"
passo 1: i=0 ('H')
passo 2: i=1 ('e')
passo 3: i=2 ('l')
passo 4: i=3 ('l')
passo 5: i=4 ('o')
passo 6: i=5 ('\0') → para
retorno: 5
```
### ft_swap.c
O que faz: troca os valores apontados por a e b.
Como faz: usa temporaria. temp=*a; *a=*b; *b=temp.
Entrada/Saida: recebe int *a, int *b; sem retorno, altera
  os conteudos apontados.
Cuidados: ponteiros devem ser validos (nao nulos).

*pseudo codigo*
```txt
início
  definir temp como valor de a
  atribuir a o valor de b
  atribuir b o valor de temp
fim
```
*processo*
```txt
entrada: a=3, b=5
passo 1: temp=3
passo 2: a=5
passo 3: b=3
resultado: a=5, b=3
```
### rev_print.c
O que faz: imprime a string ao contrario e finaliza com '\n'.
Como faz: acha o fim da string; volta imprimindo do ultimo ao
  primeiro caractere.
Entrada/Saida: recebe char *str; imprime invertida + '\n'.
Cuidados: nao altera a string original; apenas escreve.

*pseudo codigo*
```txt
início
  definir i como 0
  enquanto caractere na posição i existir
    incrementar i
  definir last como i - 1
  enquanto last >= 0
    imprimir caractere na posição last
    decrementar last
  imprimir '\n'
fim
```
*processo*
```txt
entrada: "abc"
passo 1: len=3 → last=2
passo 2: imprime 'c' (last=1)
passo 3: imprime 'b' (last=0)
passo 4: imprime 'a' (last=-1)
passo 5: imprime '\n'
saída: cba\n
```
### first_word.c
O que faz: imprime a primeira palavra da linha e finaliza com
  '\n'.
Como faz: pula espacos/tabs iniciais; imprime ate espaco, tab
  ou fim de string.
Entrada/Saida: usa argv[1] como entrada; saida eh a primeira
  palavra + '\n'.
Cuidados: se houver apenas espacos, imprime apenas '\n'.

*pseudo codigo*
```txt
início
  definir i como 0
  enquanto caractere na posição i for espaço ou tab
    incrementar i
  enquanto caractere na posição i existir e não for espaço/tab
    imprimir caractere na posição i
    incrementar i
  imprimir '\n'
fim
```
*processo*
```txt
entrada: "   hello  world"
passo 1: pula espaços até 'h'
passo 2: imprime 'h','e','l','l','o'
passo 3: para no espaço
passo 4: imprime '\n'
saída: hello\n
```
### ft_strrev.c
O que faz: inverte a string em memoria (troca caracteres).
Como faz: dois indices (inicio e fim) trocam os caracteres
  das pontas e caminham ao centro.
Entrada/Saida: recebe char *str; retorna o mesmo ponteiro
  com o conteudo invertido.
Cuidados: a string deve ser mutavel (nao literal).

*pseudo codigo*
```txt
início
  definir i como 0
  enquanto caractere na posição i existir
    incrementar i
  definir last como i - 1
  definir i como 0
  enquanto i < last
    trocar caractere em i com caractere em last
    incrementar i
    decrementar last
retornar string
fim
```
*processo*
```txt
entrada: "abcd"
passo 1: len=4 → i=0, last=3
passo 2: troca [0]<->[3] → "dbca"
passo 3: i=1,last=2 troca → "dcba"
passo 4: i=2,last=1 → para
retorno: "dcba"
```
### rot_13.c
O que faz: aplica ROT13 nas letras; demais caracteres ficam
  iguais.
Como faz: 'A'..'M'/'a'..'m' somam 13; 'N'..'Z'/'n'..'z'
  subtraem 13. Imprime cada caractere.
Entrada/Saida: argv[1] como entrada; saida eh o texto
  transformado + '\n'.
Cuidados: so letras mudam; numeros e sinais permanecem.

*pseudo codigo*
```txt
início
  para cada caractere c na string
    se c entre 'A'..'M' ou 'a'..'m'
      c ← c + 13
    senão se c entre 'N'..'Z' ou 'n'..'z'
      c ← c - 13
    imprimir c
  imprimir '\n'
fim
```
*processo*
```txt
entrada: "Hello"
passo 1: H→U
passo 2: e→r
passo 3: l→y
passo 4: l→y
passo 5: o→b
saída: Uryyb\n
```
### rotone.c
O que faz: avanca uma letra (Z->A, z->a). Outros chars igual.
Como faz: 'A'..'Y'/'a'..'y' somam 1; 'Z'/'z' voltam para
  'A'/'a'.
Entrada/Saida: argv[1] como entrada; imprime texto + '\n'.
Cuidados: apenas letras mudam; preserve espacos e pontuacao.

*pseudo codigo*
```txt
início
  para cada caractere c na string
    se c entre 'A'..'Y' ou 'a'..'y'
      c ← c + 1
    senão se c == 'Z'
      c ← 'A'
    senão se c == 'z'
      c ← 'a'
    imprimir c
  imprimir '\n'
fim
```
*processo*
```txt
entrada: "Zoo zebra!"
passo 1: Z→A
passo 2: o→p
passo 3: o→p
passo 4: ' ' fica
passo 5: z→a
passo 6: e→f
passo 7: b→c
passo 8: r→s
passo 9: a→b
passo 10: ! fica
saída: App afcsb!\n
```
### inter.c
O que faz: imprime os caracteres comuns a s1 e s2, na ordem
  de s1, sem repetir.
Como faz: para cada char de s1, se nao apareceu antes em s1 e
  existe em s2, imprime.
Entrada/Saida: argv[1] e argv[2]; saida sao os chars comuns.
Cuidados: comparacao eh exata (case-sensitive).

*pseudo codigo*
```txt
início
  para cada caractere em s1
    se caractere não apareceu antes em s1
      se caractere existe em s2
        imprimir caractere
fim
```
*processo*
```txt
entrada: s1="apple", s2="peach"
passo 1: 'a' novo e em s2 → imprime 'a'
passo 2: 'p' novo e em s2 → imprime 'p'
passo 3: 'p' repetido → ignora
passo 4: 'l' não está em s2 → ignora
passo 5: 'e' em s2 → imprime 'e'
saída: ape
```
### last_word.c
O que faz: imprime a ultima palavra da linha e finaliza com
  '\n'.
Como faz: vai ao fim, recua espacos/tabs finais, marca fim da
  palavra, recua ate o espaco anterior e imprime o trecho.
Entrada/Saida: argv[1]; imprime a palavra + '\n'.
Cuidados: multiplos espacos no fim nao atrapalham.

*pseudo codigo*
```txt
início
  definir i como tamanho da string - 1
  enquanto i >= 0 e caractere for espaço ou tab
    decrementar i
  definir fim como i
  enquanto i >= 0 e caractere não for espaço ou tab
    decrementar i
  definir início como i + 1
  para k de início até fim
    imprimir caractere na posição k
  imprimir '\n'
fim
```
*processo*
```txt
entrada: "  ola   mundo  "
passo 1: vai ao fim e recua espaços
passo 2: marca fim no 'o' de "mundo"
passo 3: recua até espaço antes da palavra
passo 4: início = próxima letra
passo 5: imprime de início a fim → "mundo"
passo 6: imprime '\n'
saída: mundo\n
```
### union.c
O que faz: imprime a uniao de caracteres: unicos de s1 na
  ordem, depois os de s2 que ainda nao apareceram.
Como faz: imprime chars unicos de s1; varre s2 e imprime os que
  nao estao em s1 e nao repetem em s2 antes.
Entrada/Saida: argv[1], argv[2]; saida eh a sequencia unida.
Cuidados: mantem ordem de aparicao; nao ordena alfabeticamente.

*pseudo codigo*
```txt
início
  para cada caractere em s1
    se caractere não apareceu antes em s1
      imprimir caractere
  para cada caractere em s2
    se caractere não está em s1 e não apareceu antes em s2
      imprimir caractere
fim
```
*processo*
```txt
entrada: s1="abc", s2="bcd"
passo 1: de s1: 'a','b','c'
passo 2: de s2: 'b' já tem → pula
passo 3: de s2: 'c' já tem → pula
passo 4: de s2: 'd' novo → imprime
saída: abcd
```
### wdmatch.c
O que faz: se argv[1] for subsequencia de argv[2], imprime
  argv[1]; senao, apenas '\n'.
Como faz: percorre argv[2] e avanca indice de argv[1] quando
  encontra o mesmo caractere na ordem.
Entrada/Saida: duas strings; imprime argv[1] + '\n' se couber
  como subsequencia; senao '\n'.
Cuidados: subsequencia nao exige contiguidade.

*pseudo codigo*
```txt
início
  definir i como 0
  definir j como 0
  enquanto caractere em texto e caractere em alvo
    se texto[j] == alvo[i]
      incrementar i
    incrementar j
  se alvo terminou
    imprimir alvo
  imprimir '\n'
fim
```
*processo*
```txt
entrada: alvo="abc", texto="a1b2c3"
passo 1: acha 'a' → i=1
passo 2: acha 'b' → i=2
passo 3: acha 'c' → i=3 (fim do alvo)
passo 4: imprime alvo e '\n'
saída: abc\n
```
### ft_range.c
O que faz: cria um vetor com inteiros de start ate end
  (inclusive), subindo ou descendo.
Como faz: calcula |end-start|+1, aloca o vetor e preenche de
  start ate end, incrementando ou decrementando 1.
Entrada/Saida: int start, int end; retorna int* com a
  sequencia.
Cuidados: quem chama deve liberar a memoria alocada.

*pseudo codigo*
```txt
início
  calcular size como |end - start| + 1
  alocar vetor com size posições
  definir atual como start
  para i de 0 até size - 1
    vetor[i] recebe atual
    se start <= end
      incrementar atual
    senão
      decrementar atual
retornar vetor
fim
```
*processo*
```txt
entrada: start=3, end=7
passo 1: size=|7-3|+1=5
passo 2: preenche: 3,4,5,6,7
retorno: [3,4,5,6,7]
```
### ft_itoa.c
O que faz: converte um int para string (com sinal se preciso).
Como faz: calcula o tamanho (contando '-' ou '0'), aloca e
  preenche de tras para frente com nb%10; se negativo, coloca
  '-' no inicio.
Entrada/Saida: recebe int n; retorna char* terminado em '\0'.
Cuidados: tratar INT_MIN usando long para evitar overflow.

*pseudo codigo*
```txt
início
  nb ← (long) n
  calcular len (contando '-' se n<0, '0' se n==0)
  alocar string com len+1 e terminar em '\0'
  se nb == 0
    string[0] = '0' e retornar
  se nb < 0
    marcar sinal e nb = -nb
  preencher string do fim para o início com nb%10
  se sinal marcado
    colocar '-' no início
retornar string
fim
```
*processo*
```txt
entrada: n=-120
passo 1: len=4 (sinal + 3 dígitos)
passo 2: preencher de trás: '0','2','1'
passo 3: sinal '-' na frente
retorno: "-120"
```
### ft_split.c
O que faz: divide a string em palavras usando varios
  separadores (charset).
Como faz: conta palavras, aloca char** (total+1), varre str
  pulando separadores e copia cada palavra nova; finaliza com
  NULL.
Entrada/Saida: char *str, char *charset; retorna char**
  terminado em NULL.
Cuidados: dar free em cada palavra e no vetor ao final.

*pseudo codigo*
```txt
início
  contar palavras separadas por caracteres do charset
  alocar vetor de palavras (total+1)
  percorrer str
    se for separador, pular
    senão, extrair palavra até próximo separador
      adicionar ao vetor
  finalizar vetor com NULL
retornar vetor
fim
```
*processo*
```txt
entrada: str="Words to.be/splitted*in@six"
charset: "./*@! "
passo 1: conta 6 palavras
passo 2: extrai "Words", "to", "be", "splitted", "in", "six"
retorno: ["Words","to","be","splitted","in","six",NULL]
```
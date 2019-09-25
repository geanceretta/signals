# signals
Operational systems POSIX signals handling

# Goal (PT_br):
Escreva um programa que realiza tratamento de sinais POSIX. O programa deve:
  Contar quantas vezes o usuário envia o sinal SIGINT (Ctrl-C) para o processo em execução.
  Quando o sinal receber um SIGTSTP (Ctl-Z), ele deve imprimir o número de sinais SIGINT que
ele recebeu.
  Depois de ter recebido 10 SIGINT’s, o programa deve “convidar” o usuário a sair (“Really exit
(Y/n)?”).
    Se o usuário não responder em 5 seg., o programa finaliza
    Se responder ‘Y’ manda um sinal de termino a ele próprio.
    Se responder ‘n’ reinicia contagem

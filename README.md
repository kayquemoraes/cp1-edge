

# Checkpoint 1 - O Caso da VinheriaAgnello

**Nome dos participantes:**
- Guilherme Silva Dos Santos
- Kayque Moraes Dias
- Laís Granero Bertoncello
- Wesley de Souza Silva
- Samuel Ramos de Almeida

**Turma:** 1º ESPX

**Ano:** 2023
___

<img src="img/projeto_tinkercad.png">

## Descrição do desafio

Fomos contratados pela Vinheria Agnello para desenvolver um sistema de monitoramento a ser instalado no ambiente em que os vinhos são armazenados. O dono a Vinheria informou que a qualidade do vinho é influenciada diretamente pelas condições de temperatura, umidade e luminosidade do ambiente. Neste primeiro momento, você propôs ao dono da Vinheria um projeto em etapas, de modo que seu 1° desafio é:

- Elaborar um sistema usando Arduino que faça a captura das informações de luminosidade do ambiente.  Para isso pesquise sobre o LDR. Verifique como eles funcionam e como poderiam ser usados no projeto.

- Depois dos dados coletados, implemente um sistema de alarme, utilizando LEDs, para sinalizar quando o a ambiente estiver OK, ou quando alguma grandeza estiver fora dos limites estipulados.  Use um LED verde para indicar que está OK, um LED amarelo para indica que está em níveis de alerta e um LED Vermelho para indicar que tem algum problema.

- Quando a luminosidade estiver em nível de alerta, deve soar uma buzina (buzzer) por 3 segundos. A buzina volta a soar caso a luminosidade permaneça em nível de alerta.
___

## Desenvolvimento do projeto
O primeiro passo para a iniciação do projeto foi entender como um LDR funciona. O LDR é um resistor passivo que varia sua resistência conforme a intensidade de luz que incide sobre ele, além disso possui apenas dois terminais e não tem polaridade definida. O sensor é conectado na porta analógica, e o próximo passo foi entender como a porta analógica fazia a leitura destes dados vindos do LDR. Concluímos que a leitura dos dados é passada em um intervalo de 10 bits, sendo 54 bits o valor com nenhuma luminosidade, e 974 bits o valor com luminosidade máxima. 

A maior dificuldade do projeto foi descobrir o que era considerado um valor ideal de luminosidade para o vinho, já que só tinhamos valores em bits para trabalhar. Todos os materiais sobre vinhos que procuravamos utilizava a unidade de medida "lux" para informar a luminosidade ideal para o vinho. A partir disso, o desafio seguinte era utilizar o que tinhamos (bits) para chegar em lux, e assim dar continuidade no projeto.

O grande passo para a solução deste desafio foi converter os bits que tinhamos em volts, sendo 0 bits o valor correspondente à 0 volts, e 1023 bits à 5 volts. Dessa forma ficou mais fácil de trabalhar, já que a essa altura a maior parte dos nossos problemas poderia ser resolvido com a lei de ohm.

Pelos materias que encontramos provenientes de pesquisas sobre vinhos, a luminosidade em que o vinho deve ficar está relacionada diretamente com o a área do local em que o vinho ficará armazenado, e a quantidade de vinho. Porém, utilizamos um valor médio apresentado nestas pesquisas, sendo de 280 à 380 lux um valor ideal para a iluminação dos vinhos. A partir disso, utilizando condicionais da linguagem, conseguimos estabelecer regras para a funcionalidade do projeto.

___
   
## Pré-requisitos

Para utilizar este projeto, você precisará de:

   #### HARDWARE  

   - Aduino Uno 
   - Bateria 3.0V
   - LDR 
   - 3 LED´S
   - 1 resistore de 220 ohm
   - 1 resistor de 1k ohm
   - Buzzer (buzina)
   - Protoboard 830 Pontos
   - 16 jumpers

   #### SOFTWARE 

   - Arduino IDE
   
___
## Como executar o projeto

Após a instalação do Arduíno IDE, você deve seguir os seguintes passos:

1. Faça download do código da pasta "Código Fonte" deste repositório.
2. Abra o código no Arduino IDE.
3. Conecte os sensores e componentes de acordo com as instruções fornecidas no código.

***Você também pode executar a simulação do projeto online através do link:*** https://www.tinkercad.com/things/3cG0uZoqopW
___

## Video Explicativo
Link do vídeo: https://drive.google.com/file/d/1rcWSbPRsI1FaB0sQf5cOTaA53iPp0vEZ/view
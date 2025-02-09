# Controle de Servomotor por PWM com RP2040

## Descrição do Projeto

Este projeto visa o controle do ângulo de um servomotor utilizando modulação de largura de pulso (PWM) no microcontrolador **RP2040** da **Raspberry Pi Pico W**. A simulação será realizada no ambiente de desenvolvimento **VS Code**, utilizando o **Pico SDK**, e será conduzida no simulador de eletrônica online **Wokwi**.

O objetivo é controlar a posição do servo motor micro padrão em três posições fixas (0°, 90° e 180°) e realizar uma movimentação contínua entre essas posições com um incremento suave do pulso.

### Componentes Utilizados:
1. **Microcontrolador**: Raspberry Pi Pico W
2. **Servomotor**: Motor micro servo padrão (simulação no Wokwi)
3. **Ambiente de Desenvolvimento**: Visual Studio Code + Pico SDK
4. **Simulador de Eletrônica**: Wokwi

### Requisitos

1. **Configuração do PWM**:
   - A GPIO 22 deve ser configurada para gerar um sinal PWM com frequência de **50Hz** (período de 20ms).
   - O ciclo ativo (Duty Cycle) do PWM deve ser configurado para:
     - **2.400µs** (aproximadamente 180 graus), aguardando **5 segundos**.
     - **1.470µs** (aproximadamente 90 graus), aguardando **5 segundos**.
     - **500µs** (aproximadamente 0 grau), aguardando **5 segundos**.

2. **Movimentação Contínua**:
   - Após as configurações acima, o servo deve se mover periodicamente entre 0° e 180°, com um incremento de **±5µs** a cada **10ms**, proporcionando uma movimentação suave.

3. **Experimento com LED RGB**:
   - Usar o código para controlar o **LED RGB** no **GPIO 12** e observar seu comportamento ao ser integrado com o PWM.

---

## Instruções de Implementação

### Configuração do PWM

O PWM é configurado utilizando a GPIO 22, com a frequência de 50Hz, que resulta em um período de 20ms. O ciclo ativo é ajustado para **2.400µs** para o servo alcançar a posição de **180°**, **1.470µs** para **90°**, e **500µs** para **0°**.

## video demonstrativo:


[![Assista ao vídeo demonstrativo](https://i.ytimg.com/vi/m4CvZlHNlw0/hq720_2.jpg?sqp=-oaymwEoCJUDENAFSFryq4qpAxoIARUAAIhC0AEB2AEB4gEKCBgQAhgGOAFAAQ==&rs=AOn4CLDEAiMRf0h5bnH_93G-STIvsmkGAQ)](https://youtu.be/B6vUotabbRA?si=Dc5PJno0R4BkYyAp)
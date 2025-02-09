#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PINO_PWM 22
#define PULSO_MIN 500
#define PULSO_MEIO 1470
#define PULSO_MAX 2400

#define VALOR_TOP 20000
#define DIVISOR_CLK 125.0

// inicializa pwm
void inicializa_pwm_do_servo(uint pino) {
    uint slice_pwm = pwm_gpio_to_slice_num(pino);
    gpio_set_function(pino, GPIO_FUNC_PWM);  // Define função PWM para o pino
    
    pwm_set_enabled(slice_pwm, false);  // desliga o PWM antes da configuração

    pwm_set_wrap(slice_pwm, VALOR_TOP);  // Define o valor do contador 
    pwm_set_clkdiv(slice_pwm, DIVISOR_CLK);  // Ajusta o divisor do clock para 1MHz

    pwm_set_chan_level(slice_pwm, pwm_gpio_to_channel(pino), 0);  // inicia com duty cycle 0

    pwm_set_enabled(slice_pwm, true);  // liga o PWM depois de configurar
}

// Função para gerar o pulso desejado em microssegundos
void ajustar_duracao_pulso(uint pino, uint16_t duracao_us) {
    uint slice_pwm = pwm_gpio_to_slice_num(pino);
    uint canal_pwm = pwm_gpio_to_channel(pino);
    pwm_set_chan_level(slice_pwm, canal_pwm, duracao_us); // Ajusta a duração do pulso no canal PWM
}

// Função para realizar os movimentos fixos do servo
void movimentos_fixos_servo(uint pino) {
    // Movimento para 180 graus (2400us)
    ajustar_duracao_pulso(pino, PULSO_MAX);
    sleep_ms(5000);

    // Movimento para 90 graus (1470us)
    ajustar_duracao_pulso(pino, PULSO_MEIO);
    sleep_ms(5000);

    // Movimento para 0 grau (500us)
    ajustar_duracao_pulso(pino, PULSO_MIN);
    sleep_ms(5000);
}

// Função para subir o pulso de 500us até 2400us
void subir_pulso(uint pino) {
    for (uint16_t duracao = PULSO_MIN; duracao <= PULSO_MAX; duracao += 5) {
        ajustar_duracao_pulso(pino, duracao);
        sleep_ms(10);  // Atraso para movimento suave
    }
}

// Função para descer o pulso de 2400us até 500us
void descer_pulso(uint pino) {
    for (uint16_t duracao = PULSO_MAX; duracao >= PULSO_MIN; duracao -= 5) {
        ajustar_duracao_pulso(pino, duracao);
        sleep_ms(10);  // Atraso para movimento suave
    }
}

// Função principal
int main() {
    stdio_init_all();

    // Configura o PWM para o pino especificado
    inicializa_pwm_do_servo(PINO_PWM);

    // Movimentos fixos do servo motor
    movimentos_fixos_servo(PINO_PWM);

    // Movimento contínuo de 0 a 180 graus
    // Passo de 5us a cada 10ms para movimento suave
    while (true) {
        // Sobe o pulso de 500us até 2400us
        subir_pulso(PINO_PWM);
        
        // Desce o pulso de 2400us até 500us
        descer_pulso(PINO_PWM);
    }

    return 0;
}

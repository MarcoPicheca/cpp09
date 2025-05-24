#ifndef RNP_HPP
#define RNP_HPP
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>


/**
 * 
 * Il programma deve prendere un reverse Polish mathematical
 * expression i cui numeri saranno sempre < 10.
 * 
 * non so perchè ma hanno scritto che il calcolo e il risultato
 * non terranno conto della regola precedente (cioè duhhh?!)
 * 
 * L'espressione stamperà il risultato sullo stdout.
 * 
 * se incappi in un errore allora un messaggio di errore
 * verrà stampato.
 * 
 * I tokens accettabili oltre ai numeri sono '/ * - + '
 * ovvero le operazione basilari di algebra
 * 
 * esempio:
 *  $> ./RPN "7 7 * 7 -" => 7 * 7 - 7
	$>	42 

	$> ./RPN "1 2 * 2 / 2 * 2 4 - +" => 1 × 2 ÷ 2 × 2 + 2 − 4
	$>	0
 * 
 * 
 */

#endif
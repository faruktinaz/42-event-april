<?php
$choices = array('rock', 'paper', 'scissors');
$computer_choice = $choices[rand(0,2)];

echo "Seçiniz rock, paper, or scissors: ";
$user_choice = strtolower(trim(fgets(STDIN)));

if ($user_choice == $computer_choice) {
    echo "** Berabere. **\n";
} else if ($user_choice == 'rock' && $computer_choice == 'scissors' ||
			$user_choice == 'paper' && $computer_choice == 'rock' ||
			$user_choice == 'scissors' && $computer_choice == 'paper') {
    echo "** Tebrikler, kazandın! Bilgisayarın seçimi: $computer_choice. **\n";
} else {
    echo "** Kaybettin. Bilgisayarın seçimi: $computer_choice. **\n";
}
?>
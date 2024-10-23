const game = ["Pierre", "Feuille", "Ciseaux"];
let playerScore = 0;
let computerScore = 0;

const play = input => {
    const playerChoice = input.value;
    const  computerChoice = game[Math.floor(Math.random() * game.length)];
    console.log(playerChoice);
    console.log(computerChoice);
}

document.getElementsByClassName("boutton")
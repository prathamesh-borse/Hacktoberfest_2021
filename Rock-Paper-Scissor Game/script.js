function getComputerChoose() {
    var comp = Math.random();
    if (comp < 0.34){
        comp = 'rock';
    } else if (comp >= 0.35 && comp < 0.67){
        comp = 'scissor';
    } else{
        comp = 'paper';
    }
    return comp;
}

function getResult(comp,player) {
    var result = '';
    if (player == comp){
        result = '-- Draw --';
    } else if (player == 'rock'){
        if (comp == 'scissor') {
            result = '-- Win --';
        } else{
            result = '-- Lose --';
        }
        // result = (comp == 'scissor') ? '-- Win --' : '-- Lose --';
    } else if (player == 'scissor'){
        if (comp == 'paper') {
            result = '-- Win --';
        } else{
            result = '-- Lose --';
        }
    } else if (player == 'paper'){
        if (comp == 'rock') {
            result = '-- Win --';
        } else{
            result = '-- Lose --';
        }
    } else{
        result = '-- Tidak Valid -- \nKamu memasukan pilihan yang salah. Pilih rock, scissor, atau paper!';
    }
    return result;
}

function turnOn() {
    const imgComputer = document.querySelector('.img-computer');
    const image = ['rock', 'scissor', 'paper'];
    let i = 0;
    const timeStart = new Date().getTime();
    setInterval(function(){
        if(new Date().getTime() - timeStart > 1000){
            clearInterval;
            return;
        }
        imgComputer.setAttribute('src','img/'+ image[i++] + '.png');
        if (i==image.length) {
            i=0;
        }
    }, 100)
}

const pilihan = document.querySelectorAll('li img');
pilihan.forEach(function(pil) {
    pil.addEventListener('click',function(){
        const playerChoose = pil.name;
        const computerChoose = getComputerChoose();
        const result = getResult(computerChoose,playerChoose);

        turnOn();

        setTimeout(function(){
            const imgComputer = document.querySelector('.img-computer');
            imgComputer.setAttribute('src','img/' + computerChoose + '.png');

            const info = document.querySelector('.info');
            info.innerHTML = result;
        },1000);
    });
});
 

//  Q1
function greet(){
    let hour=document.getElementById("hour").value;
    hour=parseInt(hour);
    if(hour>=6 && hour<=12){
        console.log("Good morning");
    }
    else if(hour>=13 && hour<=17){
        console.log("Good afternoon");
    }
    else{
        console.log("Good noght");
    }
}


// Q2
function discount(){
    let age=document.getElementById("age").value;
    age=parseInt(age);
    if((age>0 && age<=6) || (age>=65)){
        console.log("Discount");
    }
    else{
        console.log("No Discount");
    }
}


// Q3
const num=[10,20,30];
num[num.length-1]=99;
console.log(num)

// Q4
for(let i=0;i<=10;i+=2){
    console.log(i,",");
}

// Q5
for(let i=5;i>=0;i--){
    console.log(i,",");
}
 

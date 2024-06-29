let Date = new Date();
let Hour = now.getHours();

console.log('current Hour : ${Hour}');


if(Hour >=6 && Hour<=12)
{
    console.log("GOOD MORNING");
}

else if (Hour>=12 && Hour <=18)
{
    console.log("Good AFternoon");
}

else 
{
    console.log("Good Night");
}
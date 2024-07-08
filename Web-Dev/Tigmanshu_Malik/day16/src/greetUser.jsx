function GreetUser({user = "none"}){

    return(

        <p>Hello {user == "none" ? "there !": user} . It is nice to meet you !</p>
    )
}

export default GreetUser
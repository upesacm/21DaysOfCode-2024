import { useState } from "react"

function NameForm(){

    const [user, setUser] = useState("Your Name")

    const handleEvent = (event) => {

        event.preventDefault()
        
        alert(`Your name is ${user}`)
    }

    return(

        <form onSubmit={handleEvent}>
            <label>Name:</label>
            <input type="text" value={user} onChange={(event) => {
                setUser(event.target.value)
            }}></input>
            <button type="submit">Submit</button>
        </form>
    )
}

export default NameForm
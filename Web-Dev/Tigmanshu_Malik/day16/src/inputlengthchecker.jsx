import { useState } from "react"

function InputLengthChecker(){

    const [value, setValue] = useState("")

    const handleSubmit = (event) => {

        event.preventDefault()

        alert(value < 5 ? "Too short" : "Too long")
    }

    return(
        
        <form onSubmit={handleSubmit}>
            <label>Enter Length:</label>
            <input type="text" onChange={(event) => {setValue(event.target.value)}}></input>
            <button type="submit">Submit</button>
        </form>
    )
}

export default InputLengthChecker
import { useState } from "react"

function ButtonClicker(){
    
    const [value, setValue] = useState("Click Me")

    const change = () => {

        setValue("clicked")
    }

    return(
        <>
            <button onClick={change}>{value}</button>
        </>
    )
}

export default ButtonClicker
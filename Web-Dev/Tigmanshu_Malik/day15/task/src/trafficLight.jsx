import { useState } from "react";

function TrafficLight(){

    const colors = ["red", "green", "yellow"]

    const [color, setColor] = useState(0)

    const change = () => {

        setColor((color + 1) === 3 ? 0 : color + 1)
    }

    return(

        <div>
            <div style={{width: "100px", height: "100px", backgroundColor:colors[color]}}></div>
            <button onClick={change}>Change</button>
        </div>
    )
}

export default TrafficLight
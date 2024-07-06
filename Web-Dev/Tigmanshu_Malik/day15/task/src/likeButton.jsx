import { useState } from "react";

function LikeButton(){

    const [value, setValue] = useState(0)

    const change = () => {

        setValue(value + 1)
    }

    return(

        <div style={{display: "flex", margin: "10px", gap: "10px", alignContent:"center"}}>
            <button onClick={change}><i className="fa-solid fa-thumbs-up"></i></button>
            <div>This button has been clicked {value} times</div>
        </div>

    )
}

export default LikeButton
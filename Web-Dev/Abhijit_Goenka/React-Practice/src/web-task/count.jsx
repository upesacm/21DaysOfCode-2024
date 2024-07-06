import {useState} from "react";
const Like = () => {
    const [mearsure,setMeasure] = useState(0);

    const handleClick = () => {
        setMeasure(mearsure+1);

    };
    return (
        <div>
            <button onClick={handleClick}>Like</button>
            <span>Likes Count: {mearsure}</span>
        </div>


    );
};
export default Like;
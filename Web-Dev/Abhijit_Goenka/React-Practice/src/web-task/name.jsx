import {useState} from "react";
const Name = () =>{
    const[name,setName]=useState('');
    const handleSubmit=(Event) =>{
        Event.preventDefault();
        alert(`Hello Dear,${name}`);

    };


    return (
        <form onSubmit={handleSubmit}>
            <label>
                Name:
                <input type="text" value={name} onChange={(e) => setName(e.target.value)}/>
            </label>
            <button type="submit">Submit</button>



        </form>
    );
};
export default Name;


import { useState } from "react";

const Traffic = () =>{
    const [signal,setSignal] = useState('Red');

    const handleToggle = () => {
        setSignal(prevLight => {
            switch (prevLight) {
                case 'Red':
                    return 'Green';
                case 'Green':
                    return 'Yellow';
                case 'Yellow':
                    return 'Red';
                default:
                    return 'Red';


                

            }
        });
    };
    return(
        <div>
            <div style={{ height: '100px', width: '100px', backgroundColor: signal === 'Red' ? 'red' : 'white', marginBottom: '10px' }} />
            <div style={{ height: '100px', width: '100px', backgroundColor: signal === 'Yellow' ? 'yellow' : 'white', marginBottom: '10px' }} />
            <div style={{ height: '100px', width: '100px', backgroundColor: signal === 'Green' ? 'green' : 'white' }} />
            <button onClick={handleToggle}>Toggle Light</button>
        </div>








);
};
export default Traffic;
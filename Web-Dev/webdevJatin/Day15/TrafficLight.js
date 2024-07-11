import React, { useState } from 'react';

function TrafficLight() {
    const [color, setColor] = useState('Red');

    const toggleColor = () => {
        if (color === 'Red') {
            setColor('Green');
        } else if (color === 'Green') {
            setColor('Yellow');
        } else {
            setColor('Red');
        }
    };

    return (
        <div>
            <div style={{ width: '50px', height: '150px', backgroundColor: 'black', padding: '10px' }}>
                <div style={{ backgroundColor: color === 'Red' ? 'red' : 'grey', height: '30px', borderRadius: '50%', marginBottom: '10px' }}></div>
                <div style={{ backgroundColor: color === 'Yellow' ? 'yellow' : 'grey', height: '30px', borderRadius: '50%', marginBottom: '10px' }}></div>
                <div style={{ backgroundColor: color === 'Green' ? 'green' : 'grey', height: '30px', borderRadius: '50%' }}></div>
            </div>
            <button onClick={toggleColor}>Toggle</button>
        </div>
    );
}

export default TrafficLight;

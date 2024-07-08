import React, { useState } from 'react';

const InputLengthChecker = () => {
    const [input, setInput] = useState('');

    const handleChange = (event) => {
        setInput(event.target.value);
    };

    const message = input.length < 5 ? "Too short" : "Long enough";

    return (
        <div>
            <label>
                Enter text:
                <input type="text" value={input} onChange={handleChange} />
            </label>
            <p>{message}</p>
        </div>
    );
};

export default InputLengthChecker;

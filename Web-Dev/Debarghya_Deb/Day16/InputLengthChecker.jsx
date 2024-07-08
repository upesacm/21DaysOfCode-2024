import React, { useState } from 'react';

function InputLengthChecker() {
  const [inputText, setInputText] = useState('');

  const handleChange = (event) => {
    setInputText(event.target.value);
  };

  const isLongEnough = inputText.length >= 5;

  return (
    <div>
      <label>
        Enter text:
        <input type="text" value={inputText} onChange={handleChange} />
      </label>
      <p>{isLongEnough ? 'Long enough' : 'Too short'}</p>
    </div>
  );
}

export default InputLengthChecker;

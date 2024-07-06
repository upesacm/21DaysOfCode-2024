import  { useState } from 'react';

function Length() {
  const [text, setText] = useState('');

  const handleChange = (event) => 
    {
    setText(event.target.value);
  };

  return (
    <div>
      <input type="text" value={text} onChange={handleChange} />
      <p>
        {text.length < 5 ? 'Too short' : 'Long enough'}
      </p>
    </div>
  );
}

export default Length;
import React, {useState} from 'react'
const [inputText, setInputText] = useState('');
const InputLengthChecker = () =>{
    return( 
    <div>
        <input type="text" value={inputText} onChange={(e) => setInputText(e.target.value)} />
        <p>{inputText.length < 5 ? 'Too short' : 'Long enough'}</p>
     </div>
    )
}
export default InputLengthChecker
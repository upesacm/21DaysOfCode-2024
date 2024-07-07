import React , {useState} from 'react'
const [name, setName] = useState('');

const handleSubmit = (e) => {
    e.preventDefault();
    alert(`Entered name: ${name}`);
  };
const NameForm = ()=>{
    return(
        
    <form onSubmit={handleSubmit}>
      <label>
        Name:
        <input type="text" value={name} onChange={(e) => setName(e.target.value)} />
      </label>
      <button type="submit">Submit</button>
    </form>
    )
}
export default NameForm
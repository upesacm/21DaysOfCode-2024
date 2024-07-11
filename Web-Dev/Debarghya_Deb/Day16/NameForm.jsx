import React from 'react'

function NameForm() {

  const [name, setName] = React.useState("")

  const handleChange = (event) => {
    setName(event.target.value);
  }

  const handleSubmit = () => {
    alert(`HI, ${name}`)
  }

  return (
    <div>
      <form action="">
        <input 
          type="text" 
          className='name'
          name='name'
          value = {name}
          onChange={handleChange} 
        />

        <button onClick={handleSubmit} >SUBMIT</button>

      </form>
    </div>
  )
}

export default NameForm
import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App.jsx'
import './index.css'
import GreetUser from './greetUser.jsx'
import NameForm from './nameform.jsx'
import InputLengthChecker from './inputlengthchecker.jsx'

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <GreetUser user="Tigmanshu" />
    <NameForm />
    <InputLengthChecker />
  </React.StrictMode>,
)

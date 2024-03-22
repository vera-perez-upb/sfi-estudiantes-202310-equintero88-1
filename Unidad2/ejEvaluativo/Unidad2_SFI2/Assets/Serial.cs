using UnityEngine;
using System.IO.Ports;
using TMPro;
using static UnityEditor.Experimental.AssetDatabaseExperimental.AssetDatabaseCounters;
using System.Threading.Tasks;
using System;

enum TaskState
{
    INIT,
    WAIT_COMMANDS
}

public class Serial : MonoBehaviour
{

private static TaskState taskState = TaskState.INIT;
private SerialPort _serialPort;
private byte[] buffer;
public TextMeshProUGUI myText;
private string ledState = " ";
private float lastCommandTime;
private float interval = 3f;

    void Start()
{
    _serialPort = new SerialPort();
    _serialPort.PortName = "COM13";
    _serialPort.BaudRate = 115200;
    _serialPort.DtrEnable = true;
    _serialPort.NewLine = "\n";
    _serialPort.Open();
    Debug.Log("Open Serial Port");
    buffer = new byte[128];
    lastCommandTime = -interval;
    }

void Update()
{
    myText.text = "LED STATE: " + ledState;
   

    switch (taskState)
    {
        case TaskState.INIT:
            taskState = TaskState.WAIT_COMMANDS;
            Debug.Log("WAIT COMMANDS");
            break;

        case TaskState.WAIT_COMMANDS:

                if (Time.time - lastCommandTime >= interval)
                {
                    if (Input.GetKeyDown(KeyCode.A))
                    {
                        _serialPort.Write("ledON\n");
                        Debug.Log("Send ledON");
                        ledState = "ON";
                        lastCommandTime = Time.time;

                    }
                    if (Input.GetKeyDown(KeyCode.S))
                    {
                        _serialPort.Write("ledOFF\n");
                        Debug.Log("Send ledOFF");
                        ledState = "OFF";
                        lastCommandTime = Time.time;
              
                         
                    }

                    if (_serialPort.BytesToRead > 0)
                    {
                        string response = _serialPort.ReadLine();
                        Debug.Log(response);
                   
                    }
                }
            break;
        default:
            Debug.Log("State Error");
            break;
    }
}
}
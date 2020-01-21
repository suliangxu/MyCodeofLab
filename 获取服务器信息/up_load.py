import paramiko, os
from scp import SCPClient


def sshclient_execmd(hostname, port, username, password, execmd):
    paramiko.util.log_to_file("paramiko.log")
    global s
    s = paramiko.SSHClient()
    s.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    s.connect(hostname=hostname, port=port, username=username, password=password)
    stdin, stdout, stderr = s.exec_command(execmd)
    stdin.write("Y")
    print
    stdout.read()


def main():
    global hostname, port, username, password
    # hostname = "172.18.23.11"
    hostname = "172.18.22.201"
    port = 22
    username = 'root'
    password = 'test2020'
    execmd = "whoami"
    sshclient_execmd(hostname, port, username, password, execmd)
    # upload("bash -x /data/scrips/linux_system_optimization.sh")
    upload()


def upload():
    scpclient = SCPClient(s.get_transport(), socket_timeout=15.0)
    remotepath = '/root/Read_info.py'
    localpath = '/Users/hhh/Desktop/主机基线核查/获取服务器信息/Read_info.py'
    # remotepath = '/root/test.py'
    # localpath = '/Users/hhh/Desktop/主机基线核查/获取服务器信息/teat.py'
    scpclient.put(localpath, remotepath)
    s.close()

# def upload(cmd):
#     scpclient = SCPClient(s.get_transport(), socket_timeout=15.0)
#     remotepath = '/opt/linux_system_optimization.sh'
#     localpath = '/data/scrips/linux_system_optimization.sh'
#     scpclient.put(localpath, remotepath)
#     os.system(cmd)
#     s.close()


if __name__ == '__main__':
    main()
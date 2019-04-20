pipeline {
  agent { dockerfile true }

  stages {
     stage('Build') {
        steps {
             sh 'pwd'
             sh 'ls -ltr /usr/lib/'
             git url: 'file:///data/git/c_utils.git', branch: 'master'
             sh 'cmake .'
             sh 'cmake --build .'
        }
     }
  }
}

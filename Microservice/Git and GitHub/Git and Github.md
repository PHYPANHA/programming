<style>
  body, p, ul, ol, li {
    font-family: 'Khmer OS Battambang', sans-serif;
    font-size: 12pt;
    line-height: 1.6;
  }
  h1, h2, h3, h4, h5, h6 {
    font-family: 'Khmer OS Battambang', sans-serif;
    font-weight: bold;
  }
</style>

## ជំពូកទី ១: សេចក្តីផ្តើមអំពី Version Control និងការដំឡើង Git

### ១.១. តើ Version Control (ប្រព័ន្ធគ្រប់គ្រងកំណែ) គឺជាអ្វី?

**Version Control** (ជួនកាលគេហៅថា **Revision Control** ឬ **Source Control**) គឺជាប្រព័ន្ធមួយដែលតាមដានការផ្លាស់ប្តូរដែលបានធ្វើឡើងចំពោះឯកសារ ឬសំណុំឯកសារតាមពេលវេលា។ វាអនុញ្ញាតឱ្យអ្នកមើលឃើញពីការផ្លាស់ប្តូរនរណាជាអ្នកបានធ្វើវា តើឯកសារអ្វីដែលបានផ្លាស់ប្តូរ និងពេលណាដែលការផ្លាស់ប្តូរទាំងនោះត្រូវបានធ្វើឡើង។

គិតថាវាជា **'Save'** ដ៏ឆ្លាតវៃមួយសម្រាប់គម្រោងរបស់អ្នក។ ជំនួសឱ្យការរក្សាទុកឯកសារជាច្រើនដូចជា `my_project_v1.py`, `my_project_v2.py`, `my_project_final.py`, `my_project_final_really.py`... Version Control System (VCS) នឹងគ្រប់គ្រងរាល់ការផ្លាស់ប្តូរទាំងអស់នេះដោយស្វ័យប្រវត្តិ និងមានប្រសិទ្ធភាព។

ដើម្បីយល់កាន់តែច្បាស់ពី Version Control យើងនឹងពិនិត្យមើលប្រភេទសំខាន់ៗរបស់វា៖

1.  **Local Version Control Systems (LVCS)**: ទាំងនេះគឺជាប្រព័ន្ធសាមញ្ញបំផុត ដែលរក្សាទុកកំណែរបស់ឯកសារនៅលើ Local Disk ផ្ទាល់ខ្លួនរបស់អ្នក។ ឧទាហរណ៍ដូចជា RCS (Revision Control System)។
    *   **គុណសម្បត្តិ**: ងាយស្រួលដំឡើង និងប្រើប្រាស់សម្រាប់គម្រោងផ្ទាល់ខ្លួន។
    *   **គុណវិបត្តិ**: មិនអាចអនុញ្ញាតឱ្យមានការសហការជាក្រុមបានទេ ហើយបើមានបញ្ហាកុំព្យូទ័រ (ឧទាហរណ៍ Hard Drive ខូច) នោះប្រវត្តិទាំងអស់អាចបាត់បង់ដោយគ្មានការបម្រុងទុក។

2.  **Centralized Version Control Systems (CVCS)**: ដើម្បីដោះស្រាយបញ្ហានៃការសហការ LVCS បានបង្កើត CVCS ឡើង។ ប្រព័ន្ធទាំងនេះ (ដូចជា Subversion, CVS, Perforce) ប្រើ Server កណ្តាលតែមួយដើម្បីគ្រប់គ្រងកំណែទាំងអស់នៃ Codebase។ អ្នកអភិវឌ្ឍន៍ម្នាក់ៗ "Check out" ឯកសារពី Server នោះ ធ្វើការផ្លាស់ប្តូរ ហើយបន្ទាប់មក "Check in" វិញ។
    *   **គុណសម្បត្តិ**: ងាយស្រួលគ្រប់គ្រង អ្នកគ្រប់គ្រងអាចកំណត់សិទ្ធិបានយ៉ាងងាយស្រួល។ វាជាទូទៅដំណើរការល្អសម្រាប់ការសហការក្នុងក្រុមធំៗ។
    *   **គុណវិបត្តិ**: មាន **Single Point of Failure** (ប្រសិនបើ Server ខូច នោះប្រវត្តិទាំងអស់អាចបាត់បង់ ហើយក្រុមទាំងមូលមិនអាចធ្វើការបានទេ)។ ត្រូវការភ្ជាប់អ៊ីនធឺណិតជានិច្ចដើម្បីធ្វើការ Check in/out។

3.  **Distributed Version Control Systems (DVCS)**: ដើម្បីដោះស្រាយបញ្ហាគុណវិបត្តិនៃ CVCS ប្រព័ន្ធ DVCS (ដូចជា Git, Mercurial, Darcs) ត្រូវបានបង្កើតឡើង។ នៅក្នុង DVCS អ្នកប្រើប្រាស់ម្នាក់ៗមិនត្រឹមតែ Check out នូវ Files ចុងក្រោយបំផុតប៉ុណ្ណោះទេ ប៉ុន្តែពួកគេទទួលបានច្បាប់ចម្លង **ពេញលេញ** នៃ Repository ទាំងមូល រួមទាំងប្រវត្តិទាំងអស់។
    *   **គុណសម្បត្តិ**:
        *   **គ្មាន Single Point of Failure**: ដោយសារអ្នកអភិវឌ្ឍន៍ម្នាក់ៗមានច្បាប់ចម្លងពេញលេញ គ្មាន Single Point of Failure ទេ។ ប្រសិនបើ Server កណ្តាលខូច ក៏អ្នកនៅតែអាចយក Code ពី Repository របស់នរណាម្នាក់ផ្សេងទៀតបាន។
        *   **ធ្វើការក្រៅបណ្តាញ (Offline Work)**: អ្នកអាចធ្វើការ Commit, Branch, Merge ដោយមិនចាំបាច់ភ្ជាប់ទៅអ៊ីនធឺណិត ហើយ Push/Pull នៅពេលអ្នកភ្ជាប់អ៊ីនធឺណិតវិញ។
        *   **ល្បឿនលឿន**: ប្រតិបត្តិការភាគច្រើនត្រូវបានធ្វើឡើង Locally ដែលធ្វើឱ្យវាកាន់តែលឿន។
        *   **ភាពបត់បែននៃ Workflow**: អនុញ្ញាតឱ្យមាន Workflow ការងារជាច្រើនប្រភេទដូចជា Centralized, Feature Branching, Gitflow ជាដើម។
    *   **គុណវិបត្តិ**: ទាមទារឱ្យមានការយល់ដឹងកាន់តែស៊ីជម្រៅអំពី Git ដើម្បីគ្រប់គ្រងប្រវត្តិ ជាពិសេសនៅពេលមាន Merge Conflicts។

Git គឺជាឧទាហរណ៍ដ៏សំខាន់មួយនៃ DVCS។

![Version Control Concept](https://i.imgur.com/k2j1N1A.png)
*រូបភាពទី ១.១៖ គំនិតនៃ Version Control (ប្រភព៖ git-scm.com)*

### ១.២. ហេតុអ្វីត្រូវប្រើ Version Control?

ការប្រើប្រាស់ Version Control នាំមកនូវអត្ថប្រយោជន៍ជាច្រើន ជាពិសេសក្នុងការអភិវឌ្ឍន៍ Software:

1.  **តាមដានរាល់ការផ្លាស់ប្តូរ (Track Changes)**: រាល់ការផ្លាស់ប្តូរដែលអ្នកបានធ្វើត្រូវបានកត់ត្រាទុកជាមួយនឹងព័ត៌មានលម្អិតដូចជា អ្នកណាជាអ្នកផ្លាស់ប្តូរ ពេលណា និងការផ្លាស់ប្តូរអ្វីខ្លះ។ នេះជួយឱ្យអ្នកយល់ពីប្រវត្តិនៃគម្រោង និងអាច audit ការផ្លាស់ប្តូរនីមួយៗបាន។
2.  **ត្រឡប់ទៅរកកំណែចាស់ (Revert to Previous Versions)**: ប្រសិនបើអ្នកធ្វើខុស រកឃើញ Bug ធំ ឬគ្រាន់តែចង់សាកល្បងគំនិតថ្មីដែលមិនដំណើរការ អ្នកអាចត្រឡប់ទៅរកកំណែមុនណាមួយនៃគម្រោងរបស់អ្នកវិញបានយ៉ាងងាយស្រួលដោយមិនបាច់បារម្ភពីការបាត់បង់ Code បច្ចុប្បន្នដែលអ្នកបានធ្វើការ។
3.  **ការសហការជាក្រុម (Collaboration)**: វាអនុញ្ញាតឱ្យអ្នកអភិវឌ្ឍន៍ជាច្រើននាក់ធ្វើការលើគម្រោងតែមួយក្នុងពេលដំណាលគ្នា ដោយមិនចាំបាច់បារម្ភពីការសរសេរជាន់គ្នាទៅវិញទៅមក។ VCS ជួយច្របាច់បញ្ចូលគ្នានូវការផ្លាស់ប្តូរពីអ្នកអភិវឌ្ឍន៍ផ្សេងៗគ្នាដោយមានប្រសិទ្ធភាព។
4.  **ការបម្រុងទុក (Backup)**: ប្រព័ន្ធ VCS ភាគច្រើន រួមទាំង Git គឺមានលក្ខណៈវិមជ្ឈការ (Distributed) ដែលមានន័យថាច្បាប់ចម្លងពេញលេញនៃប្រវត្តិគម្រោងត្រូវបានរក្សាទុកនៅលើកុំព្យូទ័ររបស់អ្នកអភិវឌ្ឍន៍ម្នាក់ៗ។ នេះផ្តល់នូវភាពធន់ខ្ពស់ចំពោះការបាត់បង់ទិន្នន័យ។
5.  **ដោះស្រាយបញ្ហា (Debugging)**: នៅពេលមាន Bug កើតឡើង អ្នកអាចពិនិត្យមើលប្រវត្តិ Commit ដោយប្រើឧបករណ៍ Git ដើម្បីកំណត់អត្តសញ្ញាណថាការផ្លាស់ប្តូរណាមួយដែលបណ្តាលឱ្យមានបញ្ហា។ នេះជួយកាត់បន្ថយពេលវេលាដែលចំណាយក្នុងការស្វែងរក Bug។

### ១.៣. តើ Git គឺជាអ្វី?

**Git** គឺជា **Distributed Version Control System (DVCS)** ដែលមានប្រជាប្រិយភាព និងត្រូវបានប្រើប្រាស់យ៉ាងទូលំទូលាយបំផុតនៅលើពិភពលោក។ វាត្រូវបានបង្កើតឡើងដោយ Linus Torvalds (អ្នកបង្កើត Linux Kernel) ក្នុងឆ្នាំ ២០០៥។

**លក្ខណៈសំខាន់ៗរបស់ Git:**

*   **Distributed (វិមជ្ឈការ)**: Git អនុញ្ញាតឱ្យអ្នកអភិវឌ្ឍន៍ម្នាក់ៗមានច្បាប់ចម្លងពេញលេញនៃ Repository ទាំងមូល (Code និងប្រវត្តិទាំងអស់) នៅលើកុំព្យូទ័ររបស់ពួកគេ។ នេះធ្វើឱ្យវាមានភាពរឹងមាំ មិនពឹងផ្អែកលើ Server ជានិច្ច និងអនុញ្ញាតឱ្យអ្នកអភិវឌ្ឍន៍ធ្វើការដោយមិនចាំបាច់ភ្ជាប់ទៅអ៊ីនធឺណិត។
*   **Fast (លឿន)**: Git ត្រូវបានរចនាឡើងដើម្បីដំណើរការលឿនខ្លាំង ជាពិសេសនៅពេលធ្វើការជាមួយ Repository ធំៗ។ ប្រតិបត្តិការភាគច្រើនត្រូវបានអនុវត្ត Locally ដែលធ្វើឱ្យវាកាន់តែមានល្បឿនលឿន។
*   **Data Integrity (សុចរិតភាពទិន្នន័យ)**: Git ប្រើប្រាស់ cryptographic hashing (SHA-1) ដើម្បីធានាសុចរិតភាពនៃប្រវត្តិ Code។ រាល់ Commit និងវត្ថុ (Object) ទាំងអស់ត្រូវបាន Checksum មុនពេលរក្សាទុក ដែលធ្វើឱ្យពិបាកក្នុងការបាត់បង់ទិន្នន័យដោយចៃដន្យ ឬចេតនា។
*   **Branching and Merging (ការបង្កើត Branch និងការច្របាច់បញ្ចូលគ្នា)**: Git ធ្វើឱ្យការបង្កើត Branch (សាខា) និងការច្របាច់បញ្ចូលគ្នាមានភាពងាយស្រួល និងរហ័ស ដែលជាចំណុចសំខាន់សម្រាប់ការអភិវឌ្ឍន៍លក្ខណៈពិសេសថ្មីៗ និងការសហការគ្នាប្រកបដោយប្រសិទ្ធភាព។

![Distributed Version Control](https://i.imgur.com/vHqVwY3.png)
*រូបភាពទី ១.២៖ Git ជា Distributed Version Control System (ប្រភព៖ git-scm.com)*

### ១.៤. ការដំឡើង Git

ដើម្បីចាប់ផ្តើមប្រើប្រាស់ Git អ្នកត្រូវដំឡើងវាទៅក្នុងកុំព្យូទ័ររបស់អ្នក។ ខាងក្រោមនេះគឺជាការណែនាំសម្រាប់ប្រព័ន្ធប្រតិបត្តិការទូទៅមួយចំនួន:

#### ១.៤.១. សម្រាប់ Windows

1.  ចូលទៅកាន់គេហទំព័រផ្លូវការរបស់ Git: [https://git-scm.com/downloads](https://git-scm.com/downloads)
2.  ចុចលើ **"Windows"** ដើម្បីទាញយកកម្មវិធីដំឡើង។
3.  ដំណើរការ `.exe` file ដែលបានទាញយក ហើយធ្វើតាមការណែនាំ។ ជាទូទៅ ការកំណត់លំនាំដើមគឺល្អ។

#### ១.៤.២. សម្រាប់ macOS

មានវិធីជាច្រើនដើម្បីដំឡើង Git នៅលើ macOS:

*   **តាមរយៈ Xcode Command Line Tools**: បើក **Terminal** ហើយវាយបញ្ចូលពាក្យបញ្ជាខាងក្រោម:
    ```bash
    xcode-select --install
    ```
    ប្រសិនបើ Git មិនទាន់បានដំឡើង វា​នឹង​ណែនាំ​អ្នក​ឱ្យ​ដំឡើង Command Line Tools ដែល​រួមបញ្ចូល Git ផងដែរ។

*   **តាមរយៈ Homebrew**: ប្រសិនបើអ្នកមាន Homebrew ដំឡើងរួចហើយ អ្នកអាចដំឡើង Git ដោយប្រើពាក្យបញ្ជា:
    ```bash
    brew install git
    ```
    ប្រសិនបើអ្នកមិនទាន់មាន Homebrew ទេ អ្នកអាចដំឡើងវាបានពី [https://brew.sh/](https://brew.sh/)។

*   **តាមរយៈកម្មវិធីដំឡើងក្រាហ្វិក (Graphical Installer)**: អ្នកអាចទាញយកកម្មវិធីដំឡើងពីគេហទំព័រផ្លូវការរបស់ Git: [https://git-scm.com/downloads](https://git-scm.com/downloads)

#### ១.៤.៣. សម្រាប់ Linux

អ្នកអាចដំឡើង Git តាមរយៈ Package Manager របស់ Distribution របស់អ្នក:

*   **Debian/Ubuntu**:
    ```bash
    sudo apt update
    sudo apt install git
    ```
*   **Fedora**:
    ```bash
    sudo dnf install git
    ```
*   **CentOS/RHEL**:
    ```bash
    sudo yum install git
    ```

#### ១.៤.៤. ផ្ទៀងផ្ទាត់ការដំឡើង Git

បន្ទាប់ពីដំឡើងរួច អ្នកអាចបើក **Command Prompt (Windows)**, **Terminal (macOS/Linux)** ហើយវាយបញ្ចូលពាក្យបញ្ជាខាងក្រោមដើម្បីផ្ទៀងផ្ទាត់ថា Git ត្រូវបានដំឡើងត្រឹមត្រូវ:

```bash
git --version
```

អ្នកនឹងឃើញកំណែរបស់ Git ដែលបានដំឡើង ឧទាហរណ៍ `git version 2.34.1`។

### ១.៥. ការកំណត់រចនាសម្ព័ន្ធ Git មូលដ្ឋាន (Basic Git Configuration)

មុនពេលអ្នកចាប់ផ្តើមប្រើប្រាស់ Git អ្នកត្រូវកំណត់ User Name និង Email Address របស់អ្នក។ ព័ត៌មាននេះនឹងត្រូវបានភ្ជាប់ជាមួយរាល់ **Commit** (ការកត់ត្រាការផ្លាស់ប្តូរ) ដែលអ្នកបានធ្វើ ហើយវាមានសារៈសំខាន់សម្រាប់ការតាមដានប្រវត្តិគម្រោង និងការកំណត់អត្តសញ្ញាណអ្នករួមចំណែក។

បើក Terminal ឬ Command Prompt ហើយវាយបញ្ចូលពាក្យបញ្ជាទាំងនេះ ដោយជំនួស `"Your Name"` និង `"your_email@example.com"` ជាមួយនឹងព័ត៌មានផ្ទាល់ខ្លួនរបស់អ្នក:

```bash
git config --global user.name "Your Name"
git config --global user.email "your_email@example.com"
```

*   `--global`: កំណត់ការកំណត់ទាំងនេះសម្រាប់រាល់ Git Repository ទាំងអស់នៅលើកុំព្យូទ័ររបស់អ្នក។ នេះជាការកំណត់ទូទៅបំផុត។
*   ប្រសិនបើអ្នកចង់កំណត់ User Name និង Email ផ្សេងគ្នាសម្រាប់ Repository ជាក់លាក់ណាមួយ អ្នកអាចចូលទៅក្នុង Folder របស់ Repository នោះ ហើយលុប `--global` ចេញពីពាក្យបញ្ជា។

អ្នកអាចផ្ទៀងផ្ទាត់ការកំណត់របស់អ្នកដោយប្រើពាក្យបញ្ជា:

```bash
git config --list
```

ឬពិនិត្យមើលការកំណត់ជាក់លាក់:

```bash
git config user.name
git config user.email
```

### ១.៦. ភាពខុសគ្នារវាង Git និង GitHub

ទោះបីជាឈ្មោះស្រដៀងគ្នា ហើយតែងតែប្រើរួមគ្នា ក៏ Git និង GitHub គឺជា Entity ពីរផ្សេងគ្នាដែលមានតួនាទីខុសគ្នាក្នុងវិស័យ Version Control និង Software Development។

#### **Git: គឺជា Tool (ឧបករណ៍)**

*   **និយមន័យ**: **Git** គឺជា **Distributed Version Control System (DVCS)** ដែលអ្នកបានរៀនខាងលើ។ វាគឺជា **Software** ដែលអ្នកដំឡើងនៅលើកុំព្យូទ័ររបស់អ្នក។
*   **គោលបំណង**: គោលបំណងចម្បងរបស់ Git គឺដើម្បី **តាមដានការផ្លាស់ប្តូរ** នៅក្នុង Source Code របស់អ្នក រក្សាទុកប្រវត្តិពេញលេញនៃការផ្លាស់ប្តូរទាំងនោះ និងអនុញ្ញាតឱ្យអ្នកត្រឡប់ទៅរកកំណែមុនៗបាន។
*   **លក្ខណៈ**: Git គឺជា **Command-Line Tool** (ទោះបីជាមាន Graphical User Interfaces - GUIs សម្រាប់ Git ក៏ដោយ)។ វាដំណើរការ **Locally** នៅលើកុំព្យូទ័ររបស់អ្នក។ អ្នកអាចប្រើ Git ដើម្បីធ្វើការលើគម្រោងមួយដោយមិនចាំបាច់ភ្ជាប់ទៅអ៊ីនធឺណិត។
*   **អ្នកបង្កើត**: Linus Torvalds ក្នុងឆ្នាំ ២០០៥។

![Git Logo](https://git-scm.com/images/logos/downloads/Git-Icon-1788C.png)

*រូបភាពទី ១.៣៖ Git Logo*

#### **GitHub: គឺជា Platform (វេទិកា)**

*   **និយមន័យ**: **GitHub** គឺជា **Web-based Hosting Service** សម្រាប់ Git Repository។ វាគឺជា **Platform Online** ដែលផ្តល់ទីកន្លែងសម្រាប់ទុក Git Repository របស់អ្នកនៅលើ **Cloud** (Server របស់ GitHub)។
*   **គោលបំណង**: គោលបំណងចម្បងរបស់ GitHub គឺដើម្បី **facilitate collaboration (សម្របសម្រួលការសហការ)** លើគម្រោង Software។ វាផ្តល់នូវ User Interface ដែលងាយស្រួលប្រើសម្រាប់មើល Code, តាមដាន Issues, ពិនិត្យ Pull Requests និងគ្រប់គ្រងគម្រោង។
*   **លក្ខណៈ**: GitHub គឺជា **Cloud-based Platform** ដែលមានន័យថាវាត្រូវការអ៊ីនធឺណិតដើម្បីប្រើប្រាស់។ វាផ្តល់នូវមុខងារសហការជាច្រើនដូចជា:
    *   **Repository Hosting**: ទុក Repository របស់អ្នកនៅលើ Cloud។
    *   **Issue Tracking**: តាមដានកំហុស (Bugs) និងលក្ខណៈពិសេសថ្មីៗ។
    *   **Pull Requests (PRs)**: ដំណើរការសម្រាប់ការបញ្ចូលការផ្លាស់ប្តូរ Code ទៅក្នុង Repository មេ។
    *   **Code Review**: ពិនិត្យ Code ដោយសមាជិកក្រុមផ្សេងទៀត។
    *   **Project Management Tools**: ឧបករណ៍សម្រាប់គ្រប់គ្រងកិច្ចការ។
*   **អ្នកបង្កើត**: Tom Preston-Werner, Chris Wanstrath, P. J. Hyett, និង Scott Chacon ក្នុងឆ្នាំ ២០០៨។ ក្រោយមកត្រូវបានទិញដោយ Microsoft ក្នុងឆ្នាំ ២០១៨។

![GitHub Logo](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c2/GitHub_Invertocat_Logo.svg/1200px-GitHub_Invertocat_Logo.svg.png)
*រូបភាពទី ១.៤៖ GitHub Logo*

#### **តើពួកគេធ្វើការជាមួយគ្នាយ៉ាងដូចម្តេច?**

គិតថា Git គឺជា **Engine (ម៉ាស៊ីន)** ហើយ GitHub គឺជា **Dashboard (ផ្ទាំងគ្រប់គ្រង)** សម្រាប់ Engine នោះ។

*   អ្នកប្រើប្រាស់ **Git** (Tool) នៅលើកុំព្យូទ័ររបស់អ្នកដើម្បីធ្វើការផ្លាស់ប្តូរ Code **Locally** (ឧទាហរណ៍ `git add`, `git commit`)។
*   បន្ទាប់មកអ្នកប្រើ **Git** ដើម្បី **Push** ការផ្លាស់ប្តូររបស់អ្នកទៅកាន់ **GitHub** (Platform) ដែល Repository របស់អ្នកត្រូវបាន Host នៅលើ Cloud។
*   សមាជិកក្រុមផ្សេងទៀតអាច **Pull** ការផ្លាស់ប្តូរទាំងនោះពី GitHub មកកុំព្យូទ័ររបស់ពួកគេ ដើម្បីធ្វើការបន្ត។

សរុបមក:

*   **Git** គឺជាបច្ចេកវិទ្យា Version Control core។
*   **GitHub** គឺជាសេវាកម្មដែលប្រើប្រាស់ Git ដើម្បីផ្តល់នូវការ Host Repository និងមុខងារសហការ។

អ្នកអាចប្រើ Git ដោយគ្មាន GitHub ប៉ុន្តែអ្នកមិនអាចប្រើ GitHub ដោយគ្មាន Git បានទេ។


## ជំពូកទី ២: ប្រតិបត្តិការមូលដ្ឋានរបស់ Git (Init, Add, Commit, Status, Log)

នៅក្នុងជំពូកនេះ យើងនឹងរៀនពីពាក្យបញ្ជាមូលដ្ឋានរបស់ Git ដែលអ្នកនឹងប្រើប្រាស់ស្ទើរតែរាល់ថ្ងៃនៅពេលធ្វើការជាមួយ Git ។ ការយល់ដឹងច្បាស់លាស់អំពីពាក្យបញ្ជាទាំងនេះគឺជាគ្រឹះដ៏សំខាន់សម្រាប់ការគ្រប់គ្រងកំណែ (Version Control) ប្រកបដោយប្រសិទ្ធភាព។

### ២.១. ការបង្កើត Git Repository ថ្មី (`git init`)

ដើម្បីចាប់ផ្តើមប្រើប្រាស់ Git សម្រាប់គម្រោងណាមួយ អ្នកត្រូវប្រាប់ Git ឱ្យចាប់ផ្តើមតាមដានការផ្លាស់ប្តូរនៅក្នុង Folder របស់គម្រោងនោះ។ ការធ្វើបែបនេះត្រូវបានគេហៅថា **Initialization (ការចាប់ផ្តើម)** ដែលបង្កើត **Git Repository**។

**Repository (ឃ្លាំង)** គឺជាកន្លែងដែល Git រក្សាទុកប្រវត្តិទាំងអស់នៃគម្រោងរបស់អ្នក រួមទាំងរាល់ Commit, Branches និង Metadata ផ្សេងៗទៀត។ វាប្រៀបដូចជា Database ដ៏តូចមួយសម្រាប់គម្រោងរបស់អ្នក។

បើក Terminal ឬ Command Prompt ចូលទៅក្នុង Folder គម្រោងរបស់អ្នក ហើយវាយបញ្ចូលពាក្យបញ្ជា `git init`:

```bash
# ឧទាហរណ៍៖ បង្កើត Folder ថ្មីសម្រាប់គម្រោងរបស់អ្នក
mkdir my_first_git_project
cd my_first_git_project

# បង្កើត Git Repository នៅក្នុង Folder នេះ
git init
```

នៅពេលអ្នកដំណើរការ `git init` Git នឹងបង្កើត Folder លាក់មួយឈ្មោះ `.git` នៅខាងក្នុង Folder គម្រោងរបស់អ្នក។ **Folder `.git` នេះគឺជា Git Repository ពិតប្រាកដ**។ វារក្សាទុកទិន្នន័យចាំបាច់ទាំងអស់សម្រាប់ Git ដើម្បីគ្រប់គ្រងកំណែនៃគម្រោងរបស់អ្នក។ **អ្នកមិនគួរលុប ឬកែប្រែ Folder នេះដោយផ្ទាល់ទេ** ព្រោះវាអាចបំផ្លាញប្រវត្តិគម្រោងរបស់អ្នក។

![Git Init](https://i.imgur.com/8QWv7sR.png)
*រូបភាពទី ២.១៖ `git init` បង្កើត .git folder*

### ២.២. ការត្រួតពិនិត្យស្ថានភាព (`git status`)

ពាក្យបញ្ជា `git status` គឺជាមិត្តដ៏ល្អបំផុតរបស់អ្នកនៅពេលធ្វើការជាមួយ Git។ វាផ្តល់ឱ្យអ្នកនូវព័ត៌មានដ៏មានសារៈសំខាន់អំពីស្ថានភាពបច្ចុប្បន្ននៃ Working Directory (Folder ការងារ) និង Staging Area របស់អ្នកធៀបនឹង Repository។

```bash
git status
```

**`git status` បង្ហាញអ្នកពី:**
*   **Branch បច្ចុប្បន្ន**: សាខា (Branch) ណាដែលអ្នកកំពុងស្ថិតនៅ។
*   **Untracked files**: ឯកសារថ្មីៗដែល Git មិនទាន់បានតាមដាននៅឡើយ។ Git នឹងណែនាំអ្នកឱ្យប្រើ `git add` ដើម្បីចាប់ផ្តើមតាមដានពួកវា។
*   **Changes not staged for commit**: ឯកសារដែលមានការផ្លាស់ប្តូរ (ត្រូវបានកែប្រែ ឬលុប) ប៉ុន្តែការផ្លាស់ប្តូរទាំងនោះមិនទាន់ត្រូវបានបញ្ចូលទៅក្នុង Staging Area សម្រាប់ Commit បន្ទាប់នៅឡើយទេ។
*   **Changes to be committed**: ឯកសារដែលមានការផ្លាស់ប្តូរដែលត្រូវបាន Add ទៅក្នុង Staging Area រួចរាល់សម្រាប់ Commit បន្ទាប់។
*   **Working tree clean**: គ្មានការផ្លាស់ប្តូរដែលមិនទាន់បាន Commit នៅក្នុង Working Directory ទេ។

#### ឧទាហរណ៍នៃការប្រើប្រាស់ `git status`:

1.  **បន្ទាប់ពី `git init` ភ្លាមៗ:**
    ```
    On branch master

    No commits yet

    nothing to commit (create/copy files and use "git add" to track)
    ```
    នេះមានន័យថាអ្នកនៅសាខា `master` (សាខាលំនាំដើម) ហើយមិនទាន់មាន Commit ណាមួយនៅឡើយ។ Working Directory របស់អ្នកគឺស្អាត។

2.  **បន្ទាប់ពីបង្កើតឯកសារថ្មី (ឧទាហរណ៍ `index.html`):**
    ```
    On branch master

    No commits yet

    Untracked files:
      (use "git add <file>..." to include in what will be committed)
            index.html

    nothing added to commit but untracked files present (use "git add" to track)
    ```
    Git បានប្រាប់អ្នកថាមានឯកសារ `index.html` ថ្មីមួយដែលវាមិនទាន់តាមដាន (Untracked) ហើយណែនាំឱ្យប្រើ `git add` ដើម្បីតាមដានវា។

3.  **បន្ទាប់ពី `git add index.html`:**
    ```
    On branch master

    No commits yet

    Changes to be committed:
      (use "git rm --cached <file>..." to unstage)
            new file:   index.html
    ```
    ឥឡូវនេះ `index.html` ត្រូវបានផ្លាស់ប្តូរពី 'Untracked' ទៅ 'Changes to be committed' (នៅក្នុង Staging Area)។

4.  **បន្ទាប់ពី Commit ហើយកែប្រែឯកសារដែលបានតាមដានរួច:**
    ```
    On branch master
    Your branch is up to date with 'origin/master'.

    Changes not staged for commit:
      (use "git add <file>..." to update what will be committed)
      (use "git restore <file>..." to discard changes in working directory)
            modified:   index.html

    no changes added to commit (use "git add" and/or "git commit -a")
    ```
    នេះបង្ហាញថាឯកសារ `index.html` ត្រូវបានកែប្រែនៅក្នុង Working Directory ប៉ុន្តែការផ្លាស់ប្តូរទាំងនោះមិនទាន់ត្រូវបាន Add ទៅ Staging Area នៅឡើយទេ។

### ២.៣. ការបន្ថែមឯកសារទៅ Staging Area (`git add`)

**Staging Area** (ជួនកាលគេហៅថា **Index**) គឺជាគំនិតដ៏សំខាន់មួយនៅក្នុង Git ។ វាជា **តំបន់រៀបចំ (preparation area)** រវាង Working Directory របស់អ្នក (កន្លែងដែលអ្នកកំពុងធ្វើការកែប្រែ Code) និង Git Repository (កន្លែងដែល Commit ត្រូវបានរក្សាទុក)។

មុនពេលអ្នកអាច Commit ការផ្លាស់ប្តូរទៅកាន់ Repository អ្នកត្រូវតែប្រាប់ Git ឱ្យច្បាស់ថា **តើការផ្លាស់ប្តូរណាខ្លះ** ដែលអ្នកចង់បញ្ចូលទៅក្នុង Commit បន្ទាប់។ នេះគឺដោយសារតែ Git អនុញ្ញាតឱ្យអ្នកបង្កើត Commit ដែលមានលក្ខណៈ `Atomic` (មានន័យថា Commit នីមួយៗផ្តោតលើការផ្លាស់ប្តូរមួយដុំតូច ជាក់លាក់ និងមានអត្ថន័យ)។

ពាក្យបញ្ជា `git add` ត្រូវបានប្រើដើម្បីដាក់ឯកសារ ឬ **ការផ្លាស់ប្តូរជាក់លាក់** ពី Working Directory ទៅក្នុង Staging Area។

```bash
# បន្ថែមឯកសារតែមួយទាំងស្រុងទៅ Staging Area
git add index.html

# បន្ថែមឯកសារច្រើន
git add index.html style.css

# បន្ថែមការផ្លាស់ប្តូរទាំងអស់ក្នុង Folder បច្ចុប្បន្នទៅ Staging Area (រួមទាំង Untracked files ផងដែរ)
git add .

# បន្ថែមការផ្លាស់ប្តូរទាំងអស់ដែលបានកែប្រែ (Modified) ឬលុប (Deleted) ទៅ Staging Area ប៉ុន្តែមិនមែន Untracked files ទេ
git add -u
```

**ចំណាំសំខាន់**: `git add` មិនត្រឹមតែបន្ថែមឯកសារថ្មីៗប៉ុណ្ណោះទេ ប៉ុន្តែវាក៏បន្ថែម **ការផ្លាស់ប្តូរ** នៅក្នុងឯកសារដែលបានតាមដានរួចហើយផងដែរ។ ប្រសិនបើអ្នកកែប្រែឯកសារមួយចំនួន បន្ទាប់មក `git add` ឯកសារទាំងនោះ ហើយបន្ទាប់មកកែប្រែឯកសារដដែលម្តងទៀត ការផ្លាស់ប្តូរទីពីរនឹងមិនស្ថិតនៅក្នុង Staging Area ទេ លុះត្រាតែអ្នក `git add` វាម្តងទៀត។

![Git Add](https://i.imgur.com/2U5XJ1x.png)
*រូបភាពទី ២.២៖ Working Directory, Staging Area, Repository (Committed)* 

### ២.៤. ការប្តេជ្ញាចិត្ត (Commit) ការផ្លាស់ប្តូរ (`git commit`)

**Commit** គឺជាការថត Snapshot (រូបថត) នៃគម្រោងរបស់អ្នកនៅពេលវេលាជាក់លាក់ណាមួយ។ រាល់ Commit គឺជា **ចំណុចសំខាន់ (milestone)** មួយនៅក្នុងប្រវត្តិគម្រោងរបស់អ្នក។ វាគឺជាកំណត់ត្រាអចិន្ត្រៃយ៍នៃសំណុំការផ្លាស់ប្តូរដែលអ្នកបានធ្វើ។

ពាក្យបញ្ជា `git commit` យកការផ្លាស់ប្តូរពី Staging Area ហើយរក្សាទុកវាទៅក្នុង Repository ជា Commit ថ្មី។ រាល់ Commit ត្រូវតែមានសារ (Commit Message) ដែលពិពណ៌នាពីការផ្លាស់ប្តូរដែលបានធ្វើឡើង។    

```bash
# Commit ការផ្លាស់ប្តូរជាមួយសារខ្លី
git commit -m "Initial commit: Add index.html"

# Commit ជាមួយសារវែងជាង (វានឹងបើក Editor សម្រាប់អ្នកសរសេរសារលម្អិត)
git commit
```

#### អត្ថន័យនៃ Commit Message ល្អ:   
Commit Message ដែលល្អគឺមានសារៈសំខាន់ណាស់សម្រាប់ក្រុម និងសម្រាប់ខ្លួនអ្នកនាពេលអនាគត។ វានឹងជួយអ្នកឱ្យយល់ពីមូលហេតុ និងអ្វីដែលបានផ្លាស់ប្តូរនៅក្នុង Commit នីមួយៗ។

*   **Summarize (សង្ខេប)**: បន្ទាត់ទីមួយ (Headline) គួរតែសង្ខេបការផ្លាស់ប្តូរក្នុងប្រយោគមួយ ដែលខ្លី និងច្បាស់លាស់ (តិចជាង ៥០-៧២ តួអក្សរ)។ ប្រើ **Imperative Mood** (ដូចជាពាក្យបញ្ជា ឧទាហរណ៍ “Add feature X” មិនមែន “Added feature X”)។
*   **Explain (ពន្យល់)**: បន្ទាប់ពីបន្ទាត់ទីមួយ អ្នកអាចទុកបន្ទាត់ទទេមួយ ហើយបន្ទាប់មកផ្តល់ព័ត៌មានលម្អិតបន្ថែមអំពីហេតុអ្វីបានជាការផ្លាស់ប្តូរទាំងនោះត្រូវបានធ្វើឡើង អ្វីដែលវាដោះស្រាយ ឬផលប៉ះពាល់របស់វា។
*   **Why, not What (មូលហេតុ មិនមែនអ្វី)**: សារ Commit ល្អគួរតែពន្យល់ពី **មូលហេតុ** ដែលអ្នកបានធ្វើការផ្លាស់ប្តូរ មិនមែនគ្រាន់តែ **អ្វី** ដែលអ្នកបានផ្លាស់ប្តូរនោះទេ។

**ឧទាហរណ៍ Commit Message មិនល្អ:**
```
Fix bug
```
(នេះមិនប្រាប់ថា Fix Bug អ្វី ហេតុអ្វី ឬផលប៉ះពាល់អ្វីទេ)

**ឧទាហរណ៍ Commit Message ល្អ:**
```
Fix: Prevent infinite loop in user authentication

Resolves issue #123.
This commit addresses a bug where users could get stuck in an infinite redirect loop
after logging in, due to an incorrect session validation check. The fix ensures
the session is correctly invalidated and redirects to the dashboard after successful login.
```

បន្ទាប់ពី Commit អ្នកអាចប្រើ `git status` ម្ដងទៀត។
```
On branch master
nothing to commit, working tree clean
```
នេះមានន័យថា Working Directory របស់អ្នកគឺស្អាតហើយ គ្មានការផ្លាស់ប្តូរដែលមិនទាន់បាន Commit ទេ។

### ២.៥. ការមើលប្រវត្តិ Commit (`git log`)

ពាក្យបញ្ជា `git log` បង្ហាញអ្នកពីប្រវត្តិ Commit ទាំងអស់នៅក្នុង Repository របស់អ្នក។ វាគឺជាឧបករណ៍ដ៏សំខាន់មួយសម្រាប់ស្វែងយល់ពីអ្វីដែលបានកើតឡើងនៅក្នុងគម្រោងរបស់អ្នកតាមពេលវេលា។

```bash
git log
```

លទ្ធផលធម្មតាគឺ:

```
commit 9d7b4c2f1e8a9d0e2c4b5a6f7e8d9c0b1a2e3f4d (HEAD -> main, origin/main)
Author: Your Name <your_email@example.com>
Date:   Mon Apr 1 10:00:00 2024 +0700

    Initial commit: Add index.html
```

**ពន្យល់ពីលទ្ធផល:**
*   **Commit Hash (SHA-1 Checksum)**: លេខសម្គាល់តែមួយគត់ (ឧទាហរណ៍ `9d7b4c2f1e...`) សម្រាប់ Commit នីមួយៗ។ Hash នេះគឺមិនអាចផ្លាស់ប្តូរបាន ហើយត្រូវបានប្រើដើម្បីសំដៅទៅ Commit ជាក់លាក់ណាមួយ។
*   **`HEAD`**: គឺជា Pointer ដែលចង្អុលទៅ Commit ចុងក្រោយបំផុតនៅលើ Branch បច្ចុប្បន្នដែលអ្នកកំពុងធ្វើការ។
*   **`main` (ឬ `master`)**: គឺជា Pointer ដែលចង្អុលទៅ Commit ចុងក្រោយបំផុតនៅលើ Branch នោះ។
*   **`origin/main`**: គឺជា Pointer ដែលចង្អុលទៅ Commit ចុងក្រោយបំផុតនៅលើ `main` Branch នៃ Remote Repository ដែលបានកំណត់ឈ្មោះ `origin` (ជាធម្មតា GitHub)។
*   **Author**: ឈ្មោះ និង Email របស់អ្នកដែលបានធ្វើ Commit។
*   **Date**: ពេលវេលាដែល Commit ត្រូវបានធ្វើឡើង។
*   **Commit Message**: សារដែលអ្នកបានសរសេរសម្រាប់ Commit នោះ។

#### ជម្រើសដែលមានប្រយោជន៍សម្រាប់ `git log`:

*   `git log --oneline`: បង្ហាញ Commit នីមួយៗក្នុងបន្ទាត់តែមួយ ដែលមាន Commit Hash ខ្លី និងសារ Commit។ ងាយស្រួលមើល overview រហ័ស។
*   `git log --graph --oneline --all`: បង្ហាញប្រវត្តិជាក្រាហ្វិក ងាយស្រួលមើលលំហូរនៃ Branches និង Merges ទាំងអស់នៅក្នុង Repository ។
*   `git log -p`: បង្ហាញការផ្លាស់ប្តូរជាក់លាក់នៅក្នុង Commit នីមួយៗ (Patch format) ។ នេះអនុញ្ញាតឱ្យអ្នកមើលឃើញ Code ដែលបានបន្ថែម ឬលុប។
*   `git log --stat`: បង្ហាញស្ថិតិសង្ខេបអំពីការផ្លាស់ប្តូរឯកសារក្នុង Commit នីមួយៗ (ឧទាហរណ៍ ចំនួនបន្ទាត់ដែលបានបន្ថែម/លុប)។
*   `git log --author="Your Name"`: បង្ហាញ Commit ទាំងអស់ដែលធ្វើឡើងដោយ Author ជាក់លាក់។
*   `git log --since="2 weeks ago"`: បង្ហាញ Commit ទាំងអស់ក្នុងរយៈពេល ២ សប្តាហ៍ចុងក្រោយ។

### ២.៦. លំហាត់អនុវត្ត

1.  បង្កើត Folder ថ្មីមួយឈ្មោះ `my_web_project`។
2.  ចូលទៅក្នុង Folder នោះ ហើយ khởi tạo Git Repository ដោយប្រើ `git init`។
3.  បង្កើតឯកសារថ្មីមួយឈ្មោះ `index.html` ហើយដាក់ Code HTML សាមញ្ញមួយចំនួននៅក្នុងវា។
4.  ប្រើ `git status` ដើម្បីមើលស្ថានភាព។ សង្កេតមើលថា `index.html` ជា `Untracked file`។
5.  Add ឯកសារ `index.html` ទៅក្នុង Staging Area ដោយប្រើ `git add index.html`។
6.  ប្រើ `git status` ម្ដងទៀត ដើម្បីមើលស្ថានភាព។ សង្កេតមើលថា `index.html` ឥឡូវស្ថិតនៅក្នុង `Changes to be committed`។
7.  Commit ការផ្លាស់ប្តូរដោយប្រើ `git commit -m "Add initial HTML structure"`។
8.  បង្កើតឯកសារថ្មីមួយទៀតឈ្មោះ `style.css` ហើយសរសេរ Code CSS សាមញ្ញមួយចំនួន។
9.  កែប្រែឯកសារ `index.html` ដោយបន្ថែម Link ទៅ `style.css` នៅក្នុង `<head>` tag។
10. ប្រើ `git status` ដើម្បីមើលថាឯកសារណាខ្លះបានផ្លាស់ប្តូរ (modified) និងឯកសារណាខ្លះជា `Untracked`។
11. Add ការផ្លាស់ប្តូរទាំងអស់ទៅ Staging Area ដោយប្រើ `git add .` (នេះនឹង Add ទាំង `style.css` និងការផ្លាស់ប្តូរក្នុង `index.html`)។
12. Commit ការផ្លាស់ប្តូរដោយប្រើ `git commit -m "Add CSS file and link it to HTML"`។
13. ប្រើ `git log --oneline` ដើម្បីមើលប្រវត្តិ Commit របស់អ្នក។
14. ប្រើ `git log --graph --oneline` ដើម្បីមើលទម្រង់ជាក្រាហ្វិក។
15. ប្រើ `git log -p` ដើម្បីមើលការផ្លាស់ប្តូរលម្អិតនៃ Commit នីមួយៗ។

#### Working Directory, Staging Area និង Repository: ទំនាក់ទំនង

ដើម្បីយល់ពីរបៀបដែល Git តាមដានការផ្លាស់ប្តូរ វាជារឿងសំខាន់ណាស់ក្នុងការយល់ដឹងពីតំបន់សំខាន់ៗទាំងបីនេះនៅក្នុង Git:

1.  **Working Directory (ឬ Working Tree)**:
    *   **អ្វីជាវា**: នេះគឺជា Folder (ថត) ជាក់ស្តែងនៅក្នុងកុំព្យូទ័ររបស់អ្នក ដែលអ្នកកំពុងធ្វើការជាមួយឯកសារគម្រោងរបស់អ្នក។ វារួមបញ្ចូលទាំងឯកសារទាំងអស់ដែលអ្នកកំពុងកែប្រែ បង្កើត ឬលុប។
    *   **ស្ថានភាព**: ឯកសារនៅក្នុង Working Directory អាចមានស្ថានភាពជាច្រើន:
        *   **Untracked**: ឯកសារថ្មីដែល Git មិនទាន់ដឹងឮពីវានៅឡើយ។
        *   **Modified**: ឯកសារដែល Git បានតាមដានរួចហើយ (ពី Commit មុន) ប៉ុន្តែអ្នកបានកែប្រែវា។
        *   **Unmodified**: ឯកសារដែលមិនទាន់ត្រូវបានកែប្រែតាំងពី Commit ចុងក្រោយ។

2.  **Staging Area (ឬ Index)**:
    *   **អ្វីជាវា**: នេះគឺជាតំបន់រៀបចំកម្រិតមធ្យម ដែលអ្នកប្រាប់ Git ថាការផ្លាស់ប្តូរណាខ្លះដែលអ្នកចង់បញ្ចូលទៅក្នុង Commit បន្ទាប់។ វាមិនមែនជា Folder ជាក់ស្តែងទេ តែជា File នៅក្នុង `.git` folder ដែលរក្សាទុកបញ្ជីឯកសារ និងការផ្លាស់ប្តូរដែលបានត្រៀមខ្លួនរួចរាល់សម្រាប់ការ Commit។
    *   **មុខងារ**: អ្នកប្រើ `git add` ដើម្បីយកការផ្លាស់ប្តូរពី Working Directory ទៅដាក់ក្នុង Staging Area។ អ្នកអាចជ្រើសរើសតែការផ្លាស់ប្តូរមួយផ្នែកពីឯកសារមួយដើម្បីដាក់ក្នុង Staging Area ផងដែរ។
    *   **អត្ថប្រយោជន៍**: វាអនុញ្ញាតឱ្យអ្នកបង្កើត Commits ដែលមានលក្ខណៈ `Atomic` (មានន័យថា Commit នីមួយៗផ្តោតលើការផ្លាស់ប្តូរមួយដុំតូច ជាក់លាក់ និងមានអត្ថន័យ)។ ឧទាហរណ៍ អ្នកអាចជួសជុល Bug និងបន្ថែម Feature ថ្មីក្នុងពេលតែមួយ ប៉ុន្តែអ្នកអាច Commit Bug Fix ដាច់ដោយឡែកពី Feature ថ្មី។

3.  **Git Repository (ឬ Local Repository)**:
    *   **អ្វីជាវា**: នេះគឺជា Folder `.git` ដែលផ្ទុកនូវប្រវត្តិ Commit ទាំងអស់នៃគម្រោងរបស់អ្នក។ រាល់ពេលអ្នក Commit ការផ្លាស់ប្តូរ Git នឹងថត Snapshot នៃអ្វីដែលនៅក្នុង Staging Area ហើយរក្សាទុកវាជា Commit នៅក្នុង Repository។
    *   **ស្ថានភាព**: ឯកសារនៅក្នុង Repository គឺជាកំណែដែលត្រូវបាន Commit រួចរាល់។

#### ទំនាក់ទំនងរវាងពួកគេ:

1.  **អ្នកចាប់ផ្តើមដោយការផ្លាស់ប្តូរឯកសារនៅក្នុង Working Directory របស់អ្នក**។ ឯកសារទាំងនេះគឺ `Modified` ឬ `Untracked`។
2.  **នៅពេលអ្នកសម្រេចចិត្តថាការផ្លាស់ប្តូរមួយចំនួនត្រូវបានត្រៀមខ្លួនសម្រាប់ Commit អ្នកប្រើ `git add` ដើម្បីផ្លាស់ទីការផ្លាស់ប្តូរទាំងនោះពី Working Directory ទៅកាន់ Staging Area**។ នេះដូចជាការដាក់របស់របរចូលក្នុងកន្ត្រកទិញទំនិញរបស់អ្នក។
3.  **នៅពេលដែលអ្នកសប្បាយចិត្តនឹងអ្វីដែលនៅក្នុង Staging Area អ្នកប្រើ `git commit` ដើម្បីរក្សាទុក Snapshot នៃ Staging Area នោះទៅក្នុង Git Repository**។ នេះដូចជាការទូទាត់ប្រាក់នៅកន្លែងបង់ប្រាក់ ហើយរបស់របរត្រូវបានកត់ត្រាជាផ្លូវការនៅក្នុងប្រវត្តិទិញទំនិញរបស់អ្នក។

**ឧទាហរណ៍ជាក់ស្តែង:**

*   អ្នកមានឯកសារ `index.html` និង `style.css` នៅក្នុង Working Directory ។
*   អ្នកកែប្រែ `index.html` (ឥឡូវ `Modified`) និងបង្កើតឯកសារថ្មី `script.js` (ឥឡូវ `Untracked`)។
*   អ្នករត់ `git status` វានឹងបង្ហាញឯកសារទាំងពីរនេះ។
*   អ្នករត់ `git add index.html` ។ ឥឡូវនេះការផ្លាស់ប្តូរនៅក្នុង `index.html` ស្ថិតនៅក្នុង Staging Area ។ `script.js` នៅតែ `Untracked`។
*   អ្នករត់ `git status` វានឹងបង្ហាញ `index.html` ជា 'Changes to be committed' ហើយ `script.js` នៅតែជា 'Untracked file'។
*   អ្នករត់ `git commit -m "Update home page"` ។ ឥឡូវនេះការផ្លាស់ប្តូរនៅក្នុង `index.html` ត្រូវបានរក្សាទុកជា Commit ។ `script.js` នៅតែ `Untracked` នៅក្នុង Working Directory។
*   អ្នករត់ `git add script.js` ។ ឥឡូវ `script.js` ស្ថិតនៅក្នុង Staging Area ។
*   អ្នករត់ `git commit -m "Add JavaScript file"` ។ ឥឡូវ `script.js` ត្រូវបានរក្សាទុកជា Commit ថ្មីមួយ។

ទំនាក់ទំនងនេះគឺជាមូលដ្ឋានគ្រឹះនៃ Git workflow ហើយការយល់ដឹងអំពីវាគឺសំខាន់សម្រាប់គ្រប់គ្រង Code របស់អ្នកប្រកបដោយប្រសិទ្ធភាព។

#### តួនាទីរបស់ Commit Object ក្នុងការផ្លាស់ប្តូរពី Staging Area ទៅ Repository

នៅពេលដែលអ្នកប្រើប្រាស់ពាក្យបញ្ជា `git commit` នោះ Git នឹងធ្វើការងារសំខាន់ៗមួយចំនួនដើម្បីផ្លាស់ប្តូរការផ្លាស់ប្តូរដែលបានរៀបចំទុកនៅក្នុង Staging Area ឱ្យទៅជាផ្នែកមួយនៃប្រវត្តិ Repository ជាអចិន្ត្រៃយ៍:

1.  **ការបង្កើត Snapshot នៃ Staging Area**:
    *   `git commit` ដំបូងបង្អស់គឺ **ថត Snapshot** (រូបថត) នៃមាតិកាទាំងអស់ដែលស្ថិតនៅក្នុង **Staging Area** នៅពេលនោះ។ Git មិនបានថត Snapshot នៃ Working Directory ទាំងមូលនោះទេ គឺមានតែអ្វីដែលអ្នកបាន `git add` ទៅក្នុង Staging Area ប៉ុណ្ណោះ។
    *   Snapshot នេះរួមបញ្ចូលទាំងឯកសារ និង Folder ទាំងអស់តាមស្ថានភាពដែលពួកវាមាននៅក្នុង Staging Area។

2.  **ការបង្កើត Commit Object**:
    *   Snapshot នេះ រួមជាមួយនឹងព័ត៌មានផ្សេងទៀត ត្រូវបានវេចខ្ចប់ទៅជា **Commit Object** ថ្មីមួយ។
    *   **Commit Object នីមួយៗផ្ទុកព័ត៌មានសំខាន់ៗដូចខាងក្រោម**:
        *   **Tree Object**: គឺជា Hash ID (SHA-1) ដែលចង្អុលទៅ Snapshot នៃ Working Directory របស់អ្នកនៅពេល Commit នោះត្រូវបានធ្វើឡើង។ វាជាតំណាងនៃមាតិកាឯកសារ និង Folder នៅពេលនោះ។
        *   **Parent Commit(s)**: គឺជា Hash ID របស់ Commit មុនៗដែល Commit បច្ចុប្បន្នត្រូវបានបង្កើតឡើង។ នេះបង្កើតបានជាខ្សែសង្វាក់នៃ Commit ដែលជាប្រវត្តិរបស់គម្រោង។ សម្រាប់ Merge Commit វាអាចមាន Parent Commit លើសពីមួយ។
        *   **Author Information**: ឈ្មោះ និង Email របស់អ្នកដែលបានធ្វើ Commit។
        *   **Committer Information**: ឈ្មោះ និង Email របស់អ្នកដែលបានអនុវត្ត Commit (ជួនកាលអាចខុសពី Author  ឧទាហរណ៍នៅពេល Rebase)។
        *   **Timestamp**: ពេលវេលាដែល Commit ត្រូវបានបង្កើត។
        *   **Commit Message**: សារដែលអ្នកបានសរសេរសម្រាប់ Commit នោះ ដែលពិពណ៌នាពីការផ្លាស់ប្តូរ។

3.  **ការរក្សាទុក Commit Object ទៅ Repository**:
    *   Commit Object ដែលបានបង្កើតឡើងនេះ ត្រូវបានរក្សាទុកទៅក្នុង **Git Repository** (នៅក្នុង Folder `.git/objects`) ជាទិន្នន័យដែលមិនអាចផ្លាស់ប្តូរបាន។
    *   Git ក៏ផ្លាស់ទី Pointer របស់ Branch បច្ចុប្បន្ន (ឧទាហរណ៍ `main` ឬ `feature`) ទៅកាន់ Commit Object ថ្មីនេះផងដែរ។ នេះមានន័យថា Branch នោះឥឡូវនេះចង្អុលទៅ Commit ចុងក្រោយបំផុត។

#### សរុបមក:

**Commit Object ដើរតួនាទីជាស្ពាន** រវាង Staging Area និង Repository ។ វាយកការផ្លាស់ប្តូរដែលបានរៀបចំទុកនៅក្នុង Staging Area បង្កើត Snapshot ពីពួកវា រួចវេចខ្ចប់ Snapshot នោះ រួមជាមួយនឹង Metadata ទាំងអស់ ទៅជាឯកតាប្រវត្តិដ៏រឹងមាំមួយ (Commit Object) ដែលត្រូវបានរក្សាទុកជាអចិន្ត្រៃយ៍នៅក្នុង Repository ។ ដំណើរការនេះធ្វើឱ្យរាល់ Commit ទាំងអស់មានលក្ខណៈឯករាជ្យ មិនអាចកែប្រែបាន និងជាចំណុចយោងដ៏សំខាន់នៅក្នុងប្រវត្តិគម្រោងរបស់អ្នក។

## ជំពូកទី ៣: ការប្រើប្រាស់ Branch និងការច្របាច់បញ្ចូលគ្នា (Merge & Conflict Resolution)

**Branching (សាខា)** គឺជាលក្ខណៈពិសេសដ៏មានអានុភាពបំផុតមួយរបស់ Git។ វាអនុញ្ញាតឱ្យអ្នកអភិវឌ្ឍន៍ធ្វើការលើលក្ខណៈពិសេសថ្មីៗ (Features) ឬជួសជុលកំហុស (Bugs) នៅក្នុងបរិយាកាសដាច់ដោយឡែកមួយ ដោយមិនប៉ះពាល់ដល់ Code មេ (Main Code)។ នៅពេលដែលការងារនៅលើ Branch នោះបានបញ្ចប់ អ្នកអាចច្របាច់បញ្ចូលគ្នា (Merge) ការផ្លាស់ប្តូរទាំងនោះទៅក្នុង Branch មេវិញ។

### ៣.១. តើ Branch គឺជាអ្វី?

គិតថា Branch ដូចជាខ្សែបន្ទាត់ដាច់ដោយឡែកនៃការអភិវឌ្ឍន៍។ នៅពេលអ្នកបង្កើត Branch ថ្មី អ្នកកំពុងបង្កើតច្បាប់ចម្លងនៃ Repository របស់អ្នកនៅចំណុចនោះ។ អ្នកអាចធ្វើការផ្លាស់ប្តូរ ចុះ Commit នៅលើ Branch ថ្មីនោះដោយមិនប៉ះពាល់ដល់ Branch មេ (ដែលជាធម្មតាឈ្មោះ `master` ឬ `main`)។

![Git Branches Concept](https://i.imgur.com/k9v9n6n.png)
*រូបភាពទី ៣.១៖ គំនិតនៃ Git Branches (ប្រភព៖ git-scm.com)*

#### ហេតុអ្វីត្រូវប្រើ Branch?

*   **ការអភិវឌ្ឍន៍លក្ខណៈពិសេស (Feature Development)**: ធ្វើការលើ Feature ថ្មីដោយមិនរំខានដល់ Code ដែលកំពុងដំណើរការ។
*   **ការជួសជុលកំហុស (Bug Fixes)**: ជួសជុល Bug នៅក្នុង Branch ដាច់ដោយឡែក។
*   **ការសហការ (Collaboration)**: អ្នកអភិវឌ្ឍន៍ជាច្រើនអាចធ្វើការលើ Branch ផ្សេងគ្នា និងច្របាច់បញ្ចូលគ្នានៅពេលដែលការងាររួចរាល់។
*   **ការបែងចែកការងារ (Isolation)**: ធានាថារាល់ការផ្លាស់ប្តូរពិសោធន៍ ឬការផ្លាស់ប្តូរដែលមិនទាន់រួចរាល់ នឹងមិនត្រូវបានបញ្ចូលទៅក្នុង Production Code ដោយចៃដន្យឡើយ។

### ៣.២. ប្រតិបត្តិការ Branch មូលដ្ឋាន

#### ៣.២.១. ការមើល Branch (`git branch`)

ដើម្បីមើល Branch ទាំងអស់នៅក្នុង Repository របស់អ្នក និងដឹងថា Branch ណាដែលអ្នកកំពុងស្ថិតនៅ (បង្ហាញដោយសញ្ញា `*`)។

```bash
git branch
```

លទ្ធផលឧទាហរណ៍:

```
* main
  feature/new-login
  bugfix/typo
```

#### ៣.២.២. ការបង្កើត Branch ថ្មី (`git branch <new_branch_name>`)

ដើម្បីបង្កើត Branch ថ្មីពី Branch ដែលអ្នកកំពុងស្ថិតនៅបច្ចុប្បន្ន:

```bash
git branch feature/add-footer
```

ពាក្យបញ្ជានេះគ្រាន់តែបង្កើត Branch ថ្មីប៉ុណ្ណោះ វាមិនផ្លាស់ប្តូរអ្នកទៅ Branch នោះទេ។

#### ៣.២.៣. ការផ្លាស់ប្តូរទៅ Branch ផ្សេង (`git checkout <branch_name>` ឬ `git switch <branch_name>`)

ដើម្បីផ្លាស់ប្តូរទៅ Branch ផ្សេង (ឧទាហរណ៍ Branch ដែលអ្នកទើបតែបង្កើត):

```bash
git checkout feature/add-footer
# ឬ
git switch feature/add-footer
```

*ចំណាំ: `git switch` គឺជាពាក្យបញ្ជាថ្មីជាងនេះដែលត្រូវបានណែនាំក្នុង Git 2.23+ ដើម្បីបំបែកមុខងារនៃការផ្លាស់ប្តូរ Branch ពី `git checkout` ដែលមានមុខងារច្រើន។*

ដើម្បីបង្កើត Branch ថ្មីហើយផ្លាស់ប្តូរទៅ Branch នោះភ្លាមៗ (នេះជាវិធីដែលប្រើញឹកញាប់):

```bash
git checkout -b feature/add-header
# ឬ
git switch -c feature/add-header
```

#### ៣.២.៤. ការលុប Branch (`git branch -d <branch_name>`)

នៅពេលដែលការងារនៅលើ Branch មួយត្រូវបានច្របាច់បញ្ចូលគ្នាទៅក្នុង Branch ផ្សេងទៀតហើយ អ្នកអាចលុប Branch នោះចោលបាន:

```bash
git branch -d feature/add-footer
```

ប្រសិនបើ Branch នោះមិនទាន់ត្រូវបាន Merge ទេ ហើយអ្នកនៅតែចង់លុបវា (ឧទាហរណ៍ អ្នកមិនចង់បានការផ្លាស់ប្តូរទាំងនោះទៀតទេ) អ្នកអាចប្រើ `-D` (Force Delete):

```bash
git branch -D feature/add-header
```

### ៣.៣. ការច្របាច់បញ្ចូលគ្នា (Merging)

**Merging** គឺជាដំណើរការនៃការបញ្ចូលការផ្លាស់ប្តូរពី Branch មួយទៅ Branch មួយទៀត។ គោលបំណងគឺដើម្បីបង្រួបបង្រួមប្រវត្តិការងារដែលបានធ្វើនៅលើ Branch ដាច់ដោយឡែកមកជា Branch តែមួយវិញ។

#### ៣.៣.១. ឧទាហរណ៍នៃ Workflow:

1.  **អ្នកចាប់ផ្តើមពី Branch មេ:**
    ```bash
git checkout main
    ```
2.  **អ្នកបង្កើត Branch ថ្មីសម្រាប់ Feature:**
    ```bash
git checkout -b feature/new-button
    ```
3.  **ធ្វើការផ្លាស់ប្តូរ និង Commit នៅលើ Branch ថ្មី:**
    ```bash
    # បង្កើត/កែប្រែឯកសារ
git add .
git commit -m "Implement new button functionality"
    ```
4.  **ត្រឡប់ទៅ Branch មេវិញ:**
    ```bash
git checkout main
    ```
5.  **ច្របាច់បញ្ចូលគ្នា (Merge) Branch Feature របស់អ្នកទៅក្នុង Branch មេ:**
    ```bash
git merge feature/new-button
    ```
    ប្រសិនបើគ្មានបញ្ហា (Conflicts) Git នឹងធ្វើ **Fast-Forward Merge** ឬ **Three-Way Merge** ដោយស្វ័យប្រវត្តិ។

#### ៣.៣.២. ប្រភេទនៃ Merge

Git មានវិធីពីរយ៉ាងក្នុងការ Merge Commits អាស្រ័យលើស្ថានភាពនៃប្រវត្តិ Branchs:

1.  **Fast-Forward Merge (ការបង្រួបបង្រួមទៅមុខលឿន)**
    *   **កើតឡើងនៅពេលណា**: នៅពេលដែល Branch ដែលអ្នកកំពុង Merge ចូល (ឧទាហរណ៍ `main`) មិនមាន Commit ថ្មីៗចាប់តាំងពី Branch របស់អ្នក (ឧទាហរណ៍ `feature/new-button`) ត្រូវបានបង្កើតមក។ និយាយម្យ៉ាងទៀត ប្រវត្តិរបស់ Branch មេ គឺជា `Ancestor` ដោយផ្ទាល់នៃ Branch Feature។
    *   **របៀបដំណើរការ**: Git មិនចាំបាច់បង្កើត Commit ថ្មីទេ។ វាគ្រាន់តែផ្លាស់ទី Pointer របស់ Branch មេទៅកាន់ Commit ចុងក្រោយនៃ Branch Feature។ វាមើលទៅដូចជាការបន្ថែម Commits ថ្មីទៅក្នុង Branch មេ។
    *   **អត្ថប្រយោជន៍**: រក្សាប្រវត្តិឱ្យមានលក្ខណៈ Linear (ជាបន្ទាត់ត្រង់) និងស្អាត។

    ```
      A -- B (main)
            \
             C -- D (feature)
    ```
    បន្ទាប់ពី `git merge feature` ពី `main`:
    ```
      A -- B -- C -- D (main, feature)
    ```

2.  **Three-Way Merge (ការបង្រួបបង្រួមបីផ្លូវ)**
    *   **កើតឡើងនៅពេលណា**: នៅពេលដែល Branch ទាំងពីរ (Branch មេ និង Branch Feature) មាន Commits ថ្មីៗរៀងៗខ្លួនចាប់តាំងពីពួកវាបានបំបែកចេញពីគ្នា។ Git ត្រូវស្វែងរក `Common Ancestor` (Commit រួមគ្នាដំបូងបំផុត) នៃ Branch ទាំងពីរ។
    *   **របៀបដំណើរការ**: Git នឹងបង្កើត Commit ថ្មីមួយដែលគេហៅថា **Merge Commit**។ Merge Commit នេះមាន Parent Commits លើសពីមួយ (ជាធម្មតាពីរ) ដែលភ្ជាប់ទៅ Commit ចុងក្រោយនៃ Branch ទាំងពីរ។
    *   **អត្ថប្រយោជន៍**: រក្សាទុកប្រវត្តិពិតប្រាកដនៃរបៀបដែល Branch ត្រូវបានបញ្ចូលគ្នា។

    ```
      A -- B -- E (main)
            \
             C -- D (feature)
    ```
    បន្ទាប់ពី `git merge feature` ពី `main`:
    ```
      A -- B -- E -- F (main)
            \	   /
             C -- D
              (feature)
    ```
    *`F` គឺជា Merge Commit*

### ៣.៤. ការដោះស្រាយ Conflicts (Conflict Resolution)

**Merge Conflict** កើតឡើងនៅពេលដែល Git មិនអាចច្របាច់បញ្ចូលគ្នានូវការផ្លាស់ប្តូរដោយស្វ័យប្រវត្តិបាន។ នេះជាធម្មតាកើតឡើងនៅពេលអ្នកអភិវឌ្ឍន៍ពីរនាក់ ឬច្រើននាក់ធ្វើការផ្លាស់ប្តូរទៅកាន់បន្ទាត់ Code ដូចគ្នានៃឯកសារតែមួយនៅលើ Branch ផ្សេងគ្នា។ Git មិនដឹងថាត្រូវរក្សាទុកការផ្លាស់ប្តូររបស់នរណាទេ ដូច្នេះវាត្រូវការការអន្តរាគមន៍ពីមនុស្ស។

នៅពេលមាន Conflict កើតឡើង Git នឹងផ្អាកដំណើរការ Merge ហើយប្រាប់អ្នក។ `git status` នឹងបង្ហាញឯកសារដែលមាន Conflict (ជាធម្មតាដាក់សញ្ញា `Unmerged paths`)។

#### ៣.៤.១. ជំហានដោះស្រាយ Conflict:

1.  **កំណត់អត្តសញ្ញាណ Conflict**: Git នឹងបង្ហាញ Conflict markers នៅក្នុងឯកសារដែលមានបញ្ហា។ ឧទាហរណ៍:
    ```
    <<<<<<< HEAD
    This is the code from the main branch, which I am currently on.
    =======
    This is the code from the feature branch, which I am trying to merge.
    >>>>>>> feature/new-feature
    ```
    *   `<<<<<<< HEAD`: បង្ហាញពី Code ពី Branch បច្ចុប្បន្នរបស់អ្នក (ឧទាហរណ៍ `main`)។
    *   `=======`: គឺជាបន្ទាត់បំបែករវាង Code ទាំងពីរ។
    *   `>>>>>>> feature/new-feature`: បង្ហាញពី Code ពី Branch ដែលអ្នកកំពុង Merge ចូល (ឧទាហរណ៍ `feature/new-feature`)។

2.  **កែសម្រួលឯកសារ**: អ្នកត្រូវលុប Conflict markers (`<<<<<<< HEAD`, `=======`, `>>>>>>> ...`) ចេញ ហើយជ្រើសរើស Code ដែលអ្នកចង់រក្សាទុក (ឬកែសម្រួលវាឱ្យបានត្រឹមត្រូវ ដើម្បីបញ្ចូល Code ទាំងពីរ ឬបង្កើត Code ថ្មី)។

    **ឧទាហរណ៍ ការដោះស្រាយ**: ប្រសិនបើអ្នកសម្រេចចិត្តរក្សា Code ទាំងពីរ ដោយបូកបញ្ចូលគ្នា៖
    ```
    This is the code from the main branch, which I am currently on.
    This is the code from the feature branch, which I am trying to merge.
    ```
    ឬប្រសិនបើអ្នកសម្រេចចិត្តរក្សាទុកតែ Code ពី `feature/new-feature`:
    ```
    This is the code from the feature branch, which I am trying to merge.
    ```

3.  **Add ឯកសារដែលបានដោះស្រាយទៅ Staging Area**: បន្ទាប់ពីកែសម្រួលរួច អ្នកត្រូវប្រាប់ Git ថា Conflict ត្រូវបានដោះស្រាយហើយ៖
    ```bash
git add <file_with_conflict>
    ```
    *អ្នកត្រូវ `git add` រាល់ឯកសារទាំងអស់ដែលមាន Conflict។*

4.  **Commit ការ Merge**: បន្ទាប់ពី Conflict ទាំងអស់ត្រូវបានដោះស្រាយ និង Add ទៅ Staging Area ហើយ អ្នកអាច Commit ការ Merge បាន៖
    ```bash
git commit -m "Merge feature/new-feature into main with conflict resolution"
    ```
    *Git នឹងបង្កើត Merge Commit Message លំនាំដើមសម្រាប់អ្នក ដែលអ្នកអាចកែប្រែបាន។*

#### ឧបករណ៍ជំនួយដោះស្រាយ Conflict

សម្រាប់ Conflicts ដែលស្មុគស្មាញ ឧបករណ៍ `Merge Tool` អាចជួយបានច្រើន។ Git អាចត្រូវបានកំណត់រចនាសម្ព័ន្ធឱ្យប្រើឧបករណ៍ខាងក្រៅ (ដូចជា VS Code, Meld, KDiff3) ដើម្បីជួយអ្នកមើលឃើញ និងដោះស្រាយ Conflicts។

```bash
git mergetool
```
ពាក្យបញ្ជានេះនឹងបើក Merge Tool ដែលបានកំណត់រចនាសម្ព័ន្ធរបស់អ្នក។

### ៣.៥. លំហាត់អនុវត្ត

1.  បន្តពីគម្រោង `my_web_project` ពីជំពូកមុនរបស់អ្នក។ (ត្រូវប្រាកដថាអ្នកបានលុប Branch មុនៗដែលមិនចាំបាច់ចេញ ប្រសិនបើមាន)។
2.  ត្រូវប្រាកដថាអ្នកនៅ Branch `main` (ឬ `master`): `git checkout main`។
3.  **បង្កើត Branch ថ្មីមួយ** សម្រាប់ Feature មួយឈ្មោះ `feature/new-header`:
    ```bash
    git checkout -b feature/new-header
    ```
4.  **នៅលើ `feature/new-header` Branch**: កែប្រែឯកសារ `index.html`។ ឧទាហរណ៍ បន្ថែម Header មួយនៅពីលើ `<title>` tag:
    ```html
    <!-- index.html -->
    <head>
      <title>My Web Project</title>
      <style>
        .header { color: blue; }
      </style>
    </head>
    <body>
      <h1 class="header">Welcome to my site!</h1>
      <p>This is the main page.</p>
    </body>
    ```
    Add និង Commit ការផ្លាស់ប្តូរនេះនៅលើ `feature/new-header`:
    ```bash
    git add index.html
    git commit -m "Add a new header section"
    ```
5.  **ប្តូរត្រឡប់ទៅ Branch `main` វិញ**:
    ```bash
    git checkout main
    ```
6.  **នៅលើ Branch `main`**: ធ្វើការផ្លាស់ប្តូរទៅកាន់ **បន្ទាត់ដូចគ្នា** ឬក្បែរៗនោះនៅក្នុង `index.html` ដើម្បីបង្ក Conflict ។ ឧទាហរណ៍ បន្ថែម Paragraph ថ្មីមួយនៅពីលើ `<title>` tag:
    ```html
    <!-- index.html -->
    <head>
      <p>Important announcement!</p>
      <title>My Web Project</title>
    </head>
    <body>
      <h1>Hello World</h1>
      <p>This is the main page.</p>
    </body>
    ```
    Add និង Commit ការផ្លាស់ប្តូរនេះនៅលើ `main`:
    ```bash
    git add index.html
    git commit -m "Add important announcement on main"
    ```
7.  **ព្យាយាម Merge `feature/new-header` ចូលទៅក្នុង `main`**:
    ```bash
    git merge feature/new-header
    ```
    *អ្នកគួរតែឃើញ Merge Conflict កើតឡើង!*

8.  **ដោះស្រាយ Conflict**:
    *   បើកឯកសារ `index.html` របស់អ្នក។ អ្នកនឹងឃើញ Conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`) ។
    *   កែសម្រួលឯកសារដើម្បីបញ្ចូល Code ទាំងពីរតាមរបៀបដែលត្រឹមត្រូវ (ឧទាហរណ៍ រក្សា Header និង Announcement)។ ឧទាហរណ៍:
    ```html
    <!-- index.html -->
    <head>
      <p>Important announcement!</p>
      <title>My Web Project</title>
      <style>
        .header { color: blue; }
      </style>
    </head>
    <body>
      <h1 class="header">Welcome to my site!</h1>
      <p>This is the main page.</p>
    </body>
    ```
    *   លុប Conflict markers ចេញ។

9.  **Add ឯកសារដែលបានដោះស្រាយ**:
    ```bash
    git add index.html
    ```

10. **Commit ការ Merge**:
    ```bash
    git commit -m "Merge feature/new-header into main, resolved conflicts"
    ```

11. **ពិនិត្យមើលប្រវត្តិ**:
    ```bash
git log --oneline --graph --all
    ```
    *អ្នកនឹងឃើញ Merge Commit ថ្មីមួយដែលភ្ជាប់ Branch ទាំងពីរ។*

12. **លុប Branch Feature**:
    ```bash
git branch -d feature/new-header
    ```

## ជំពូកទី ៤: ការចាប់ផ្តើមជាមួយ GitHub (Remote, Push, Pull, Clone)

នៅក្នុងជំពូកនេះ យើងនឹងរៀនពីរបៀបប្រើប្រាស់ GitHub ដែលជា Platform ដ៏ពេញនិយមសម្រាប់ Hosting Git Repository និងការសហការ។ GitHub មិនមែនគ្រាន់តែជាកន្លែងផ្ទុក Code ប៉ុណ្ណោះទេ តែជា Hub ដ៏ធំសម្រាប់សហគមន៍អ្នកអភិវឌ្ឍន៍ដើម្បីចែករំលែក ធ្វើការរួមគ្នា និងគ្រប់គ្រងគម្រោង។ យើងនឹងស្វែងយល់ពីរបៀបភ្ជាប់ Git Repository ក្នុងស្រុករបស់អ្នកទៅកាន់ GitHub និងរបៀបផ្លាស់ប្តូរ Code រវាងកុំព្យូទ័ររបស់អ្នក និង GitHub។

### ៤.១. ការបង្កើត GitHub Account និង Repository

#### ៤.១.១. ការបង្កើត GitHub Account

1.  ចូលទៅកាន់គេហទំព័រ [https://github.com/](https://github.com/)
2.  ចុចលើ **"Sign up"** ហើយធ្វើតាមការណែនាំដើម្បីបង្កើតគណនីរបស់អ្នក។ សូមប្រាកដថាអ្នកបានកំណត់ Email Address ត្រឹមត្រូវ ព្រោះវាត្រូវបានប្រើសម្រាប់កំណត់អត្តសញ្ញាណ Commits របស់អ្នក។

#### ៤.១.២. ការបង្កើត Repository ថ្មីនៅលើ GitHub

1.  បន្ទាប់ពីចូលគណនី GitHub រួច ចុចលើសញ្ញា **'+'** នៅជ្រុងខាងស្តាំខាងលើ រួចជ្រើសរើស **"New repository"**។
2.  **Repository name**: ដាក់ឈ្មោះ Repository របស់អ្នក (ឧទាហរណ៍: `my-web-project`)។ ឈ្មោះនេះគួរតែមានលក្ខណៈពិពណ៌នា និងឆ្លុះបញ្ចាំងពីគោលបំណងនៃគម្រោង។
3.  **Description (Optional)**: បន្ថែមការពិពណ៌នាសង្ខេបអំពីគម្រោងរបស់អ្នក។ នេះជួយឱ្យអ្នកដទៃយល់ពីអ្វីជាគម្រោងរបស់អ្នក។
4.  **Public/Private**: ជ្រើសរើសថាតើអ្នកចង់ឱ្យ Repository របស់អ្នកជាសាធារណៈ (Public) ដែលនរណាក៏អាចមើលបាន ឬឯកជន (Private) ដែលមានតែអ្នក និងអ្នកដែលអ្នកអនុញ្ញាតប៉ុណ្ណោះអាចមើលបាន។
5.  **Initialize this repository with a README**:
    *   ប្រសិនបើអ្នកកំពុងបង្កើត Repository ថ្មីទាំងស្រុងដែលមិនទាន់មាន Local Project ទេ អ្នកអាចជ្រើសរើសដើម្បីបន្ថែម `README.md` file នៅពេលនេះ។ `README.md` គឺជាឯកសារសំខាន់ដែលផ្តល់ព័ត៌មានអំពីគម្រោងរបស់អ្នក។
    *   សម្រាប់គម្រោងដែលមានស្រាប់ (Local Repository ដែលអ្នកមាន Code រួចហើយ) **គួរតែកុំជ្រើសរើសវា** ដើម្បីជៀសវាង Merge Conflict ដំបូងនៅពេលអ្នក Push Code របស់អ្នកទៅ GitHub។
6.  **Add .gitignore (Optional)**: ឯកសារ `.gitignore` ប្រាប់ Git ថាឯកសារ ឬ Folder ណាដែលគួរតែត្រូវបានមិនអើពើ ហើយមិនត្រូវបញ្ចូលទៅក្នុង Repository ឡើយ (ឧទាហរណ៍ Folder `node_modules` នៅក្នុងគម្រោង JavaScript)។ អ្នកអាចជ្រើសរើស Template សម្រាប់ភាសា ឬ Framework ជាក់លាក់។
7.  **Choose a license (Optional)**: ជ្រើសរើស License សម្រាប់គម្រោងរបស់អ្នក ប្រសិនបើវាជាគម្រោង Open Source។
8.  ចុចលើ **"Create repository"**។

GitHub នឹងបង្ហាញអ្នកនូវការណែនាំអំពីរបៀបភ្ជាប់ Local Repository របស់អ្នកទៅកាន់ Remote Repository ថ្មីនេះ។

![GitHub New Repository](https://i.imgur.com/3Z7wV7M.png)
*រូបភាពទី ៤.១៖ ការបង្កើត Repository ថ្មីនៅលើ GitHub*

### ៤.២. Remote Repository (`git remote`)

**Remote Repository** គឺជាកំណែនៃ Repository របស់អ្នកដែលត្រូវបាន Host នៅលើ Server ផ្សេងទៀត ជាធម្មតាគឺនៅលើ GitHub។ `git remote` គឺជាពាក្យបញ្ជាដែលប្រើសម្រាប់គ្រប់គ្រង Connection ទៅកាន់ Remote Repository ទាំងនោះ។

#### ៤.២.១. ការមើល Remote Repository

ដើម្បីមើល Remote Repository ដែលត្រូវបានកំណត់រចនាសម្ព័ន្ធសម្រាប់ Local Repository របស់អ្នក:

```bash
git remote -v
```

លទ្ធផលនឹងបង្ហាញឈ្មោះ Remote និង URL របស់វា (សម្រាប់ Fetching និង Pushing)។ ជាធម្មតា អ្នកនឹងឃើញ `origin` ដែលជាឈ្មោះលំនាំដើមសម្រាប់ Remote Repository មេ។

```
origin  https://github.com/yourusername/my-web-project.git (fetch)
origin  https://github.com/yourusername/my-web-project.git (push)
```

#### ៤.២.២. ការបន្ថែម Remote Repository (`git remote add`)

ប្រសិនបើអ្នកបានបង្កើត Local Git Repository រួចហើយ (ដោយ `git init`) ហើយចង់ភ្ជាប់វាទៅ GitHub Repository ថ្មី អ្នកត្រូវបន្ថែម Remote URL:

```bash
git remote add origin <remote_repository_url>
```

ឧទាហរណ៍:

```bash
git remote add origin https://github.com/yourusername/my-web-project.git
```

*   `origin`: គឺជាឈ្មោះលំនាំដើមដែល Git ប្រើដើម្បីសំដៅទៅ Remote Repository របស់អ្នក។ អ្នកអាចប្រើឈ្មោះផ្សេងក៏បាន ប៉ុន្តែ `origin` គឺជា Standard convention។
*   `<remote_repository_url>`: គឺជា URL នៃ GitHub Repository របស់អ្នក ដែលអ្នកអាចរកឃើញនៅលើទំព័រ Repository របស់អ្នកនៅលើ GitHub (ចុចលើប៊ូតុង "Code" ពណ៌បៃតង)។ URL មានពីរប្រភេទសំខាន់ៗ:
    *   **HTTPS**: `https://github.com/user/repo.git` ។ ងាយស្រួលប្រើសម្រាប់អ្នកចាប់ផ្តើមដំបូង ប៉ុន្តែអាចតម្រូវឱ្យអ្នកបញ្ចូល User Name និង Password (ឬ Personal Access Token - PAT) រាល់ពេល Push/Pull។
    *   **SSH**: `git@github.com:user/repo.git` ។ មានសុវត្ថិភាពជាង និងលឿនជាង ព្រោះវាប្រើ SSH keys សម្រាប់ការផ្ទៀងផ្ទាត់។ ទាមទារការកំណត់រចនាសម្ព័ន្ធ SSH Key នៅលើ GitHub របស់អ្នកជាមុនសិន។

### ៤.៣. ការ Upload Code ទៅ GitHub (`git push`)

**Pushing** គឺជាដំណើរការនៃការ Upload Local Commits របស់អ្នកពី Local Repository ទៅកាន់ Remote Repository (GitHub)។ នេះធ្វើឱ្យការផ្លាស់ប្តូររបស់អ្នកអាចមើលឃើញសម្រាប់អ្នកដទៃ និងជាការបម្រុងទុកដ៏សំខាន់។

```bash
git push -u origin main
```

*   `git push`: ពាក្យបញ្ជាសម្រាប់ Push Commits។
*   `-u` (ឬ `--set-upstream`): កំណត់ Upstream Branch។ នេះមានន័យថាចាប់ពីពេលនេះតទៅ នៅពេលអ្នកវាយ `git push` ឬ `git pull` Git នឹងដឹងថាវាគួរតែធ្វើការជាមួយ `origin` និង `main` Branch ដោយស្វ័យប្រវត្តិ។ **អ្នកគ្រាន់តែត្រូវការប្រើវាជាលើកដំបូងប៉ុណ្ណោះ** នៅពេលដែលអ្នក Push Branch ថ្មីទៅ Remote។ បន្ទាប់ពីនោះ អ្នកអាចប្រើ `git push` ធម្មតាបាន។
*   `origin`: ឈ្មោះរបស់ Remote Repository ដែលអ្នកចង់ Push ទៅ។
*   `main`: ឈ្មោះរបស់ Branch ក្នុង Local Repository ដែលអ្នកចង់ Push ទៅកាន់ Remote Repository។

នៅពេលអ្នកដំណើរការពាក្យបញ្ជានេះ Git អាចនឹងសុំឱ្យអ្នកបញ្ចូល User Name និង Password របស់ GitHub របស់អ្នក។ **ចំណាំសំខាន់**: GitHub លែងគាំទ្រការផ្ទៀងផ្ទាត់ដោយប្រើ Password សម្រាប់ Git Operations ទៀតហើយ។ អ្នកត្រូវប្រើ **Personal Access Token (PAT)** ឬ **SSH Key**។

*   **Personal Access Token (PAT)**: គឺជាខ្សែអក្សរដែលបានបង្កើតនៅលើ GitHub ដែលដើរតួជា Password របស់អ្នក។ អ្នកអាចបង្កើតវាបាននៅក្នុង GitHub Settings -> Developer settings -> Personal access tokens.
*   **SSH Key**: គឺជាវិធីសាស្ត្រផ្ទៀងផ្ទាត់ដ៏មានសុវត្ថិភាព និងងាយស្រួលជាង។ អ្នកបង្កើត SSH Key មួយគូ (Public និង Private) ហើយដាក់ Public Key របស់អ្នកទៅក្នុងគណនី GitHub របស់អ្នក។

![Git Push](https://i.imgur.com/kK5M3j4.png)
*រូបភាពទី ៤.២៖ Git Push Concept*

### ៤.៤. ការ Download Code ពី GitHub (`git pull`)

**Pulling** គឺជាដំណើរការនៃការ Download ការផ្លាស់ប្តូរពី Remote Repository (GitHub) មកកាន់ Local Repository របស់អ្នក។ នេះមានប្រយោជន៍ជាពិសេសនៅពេលអ្នកធ្វើការជាក្រុម ហើយសមាជិកផ្សេងទៀតបាន Push ការផ្លាស់ប្តូរទៅ GitHub ហើយអ្នកចង់ធ្វើឱ្យ Local Code របស់អ្នកទាន់សម័យ។

```bash
git pull origin main
```

*   `git pull`: ពាក្យបញ្ជាសម្រាប់ Pull Changes។
*   `origin`: ឈ្មោះរបស់ Remote Repository។
*   `main`: ឈ្មោះរបស់ Branch ដែលអ្នកចង់ Pull។

`git pull` គឺជា Shortcut សម្រាប់ប្រតិបត្តិការពីរគឺ `git fetch` បន្ទាប់មក `git merge`។

*   **`git fetch`**: ទាញយកការផ្លាស់ប្តូរ (Commits, Branches, Tags) ពី Remote Repository មក Local Repository របស់អ្នក ប៉ុន្តែ **មិនបាន Merge** ពួកវាទៅក្នុង Working Directory របស់អ្នកទេ។ ការផ្លាស់ប្តូរទាំងនោះត្រូវបានរក្សាទុកនៅក្នុង Remote-tracking Branches (ឧទាហរណ៍ `origin/main`)។
*   **`git merge`**: បន្ទាប់ពី `git fetch` រួច `git pull` នឹងធ្វើការ `git merge` ការផ្លាស់ប្តូរដែលបានទាញយក (ពី `origin/main`) ទៅក្នុង Local Branch បច្ចុប្បន្នរបស់អ្នក (ឧទាហរណ៍ `main`)។

**ពេលណាត្រូវប្រើ `git pull` ទល់នឹង `git fetch`?**
*   ប្រើ **`git pull`** នៅពេលអ្នកចង់ Update Local Branch បច្ចុប្បន្នរបស់អ្នកជាមួយនឹងការផ្លាស់ប្តូរចុងក្រោយពី Remote ភ្លាមៗ។
*   ប្រើ **`git fetch`** នៅពេលអ្នកចង់ឃើញថាមានអ្វីថ្មីនៅលើ Remote ប៉ុន្តែអ្នកមិនទាន់ចង់ Merge ពួកវាទៅក្នុង Local Working Copy របស់អ្នកនៅឡើយទេ។ នេះអនុញ្ញាតឱ្យអ្នកពិនិត្យមើលការផ្លាស់ប្តូរមុនពេលបញ្ចូលវា។

### ៤.៥. ការ Clone Repository (`git clone`)

**Cloning** គឺជាវិធីដើម្បី Download ច្បាប់ចម្លងពេញលេញនៃ Existing Git Repository (រួមទាំងប្រវត្តិ Commit ទាំងអស់) ពី Remote Server (ដូចជា GitHub) ទៅកាន់កុំព្យូទ័ររបស់អ្នក។ នេះគឺជាវិធីដែលអ្នកចាប់ផ្តើមធ្វើការលើគម្រោងដែលមានស្រាប់។

```bash
git clone <repository_url>
```

ឧទាហរណ៍:

```bash
git clone https://github.com/yourusername/my-web-project.git
```

*   `git clone`: ពាក្យបញ្ជាសម្រាប់ Clone Repository។
*   `<repository_url>`: URL នៃ GitHub Repository ដែលអ្នកចង់ Clone (អាចជា HTTPS ឬ SSH)។

នៅពេលអ្នក Clone Repository Git នឹងធ្វើដូចខាងក្រោមដោយស្វ័យប្រវត្តិ:

1.  បង្កើត Folder ថ្មីដែលមានឈ្មោះដូច Repository នៅក្នុង Current Directory របស់អ្នក។
2.  Initialize Git Repository នៅក្នុង Folder នោះ (`git init`)។
3.  Download មាតិកាទាំងអស់របស់ Repository មក។
4.  កំណត់ Remote `origin` ទៅកាន់ URL ដែលអ្នកបានផ្តល់ឱ្យ (`git remote add origin <url>`)។
5.  Checkout ទៅកាន់ Local `main` Branch (ឬ `master`) ដែលតាមដាន Remote `main` Branch របស់ `origin`។

### ៤.៦. លំហាត់អនុវត្ត

1.  ចូលគណនី GitHub របស់អ្នក ហើយបង្កើត Repository ថ្មីមួយឈ្មោះ `my-git-github-project` (កុំជ្រើសរើសដើម្បី Initialize ជាមួយ README)។
2.  បើក Terminal ចូលទៅក្នុង `my_web_project` Folder ពីជំពូកមុនរបស់អ្នក។
3.  បន្ថែម Remote Repository ទៅក្នុង Local Repository របស់អ្នក:
    ```bash
    git remote add origin https://github.com/yourusername/my-git-github-project.git
    ```
    (ត្រូវប្រាកដថាអ្នកជំនួស `yourusername` ជាមួយនឹង User Name GitHub ផ្ទាល់ខ្លួនរបស់អ្នក ហើយប្រើ URL HTTPS ឬ SSH ត្រឹមត្រូវ)។
4.  Push Local Commits របស់អ្នកទៅកាន់ GitHub:
    ```bash
    git push -u origin main
    ```
    (Git អាចនឹងសុំឱ្យអ្នក Login ។ សូមប្រើ Personal Access Token ប្រសិនបើអ្នកប្រើ HTTPS)។
5.  ចូលទៅកាន់ Repository របស់អ្នកនៅលើ GitHub ហើយពិនិត្យមើលថាឯកសាររបស់អ្នកបាន Upload ទៅហើយ។
6.  នៅលើ GitHub Repository របស់អ្នក កែប្រែឯកសារ `index.html` ដោយផ្ទាល់តាមរយៈ Web Interface (ឧទាហរណ៍ បន្ថែមបន្ទាត់ថ្មីមួយនៅក្នុង `<p>` tag) ហើយ Commit ការផ្លាស់ប្តូរនោះ។
7.  ត្រឡប់ទៅ Terminal របស់អ្នកវិញ ហើយ Download ការផ្លាស់ប្តូរពី GitHub មកកាន់ Local Repository របស់អ្នក:
    ```bash
    git pull origin main
    ```
8.  ពិនិត្យមើលឯកសារ `index.html` ក្នុង Local Folder របស់អ្នក ដើម្បីមើលការផ្លាស់ប្តូរដែលអ្នកបានធ្វើនៅលើ GitHub។
9.  (ជម្រើស) បើក Terminal នៅ Folder ផ្សេង ហើយសាកល្បង `git clone` Repository របស់អ្នកពី GitHub។
    ```bash
    # ត្រូវប្រាកដថាអ្នកនៅក្នុង Folder ថ្មី មិនមែន Folder គម្រោងដើមទេ!
    cd ..
    git clone https://github.com/yourusername/my-git-github-project.git
    ```

## ជំពូកទី ៥: ការសហការលើគម្រោង (Forking, Pull Requests, Issues) និងការធ្វើបច្ចុប្បន្នភាព Code (Syncing)

GitHub គឺជា Platform ដ៏មានអានុភាពសម្រាប់ការសហការគ្នាលើគម្រោង Software។ នៅក្នុងជំពូកនេះ យើងនឹងស្វែងយល់ពីរបៀបដែលអ្នកអភិវឌ្ឍន៍អាចធ្វើការជាមួយគ្នាយ៉ាងមានប្រសិទ្ធភាព ដោយប្រើប្រាស់មុខងារសំខាន់ៗដូចជា **Forking**, **Pull Requests** និង **Issues**។ លើសពីនេះ យើងក៏នឹងរៀនពីរបៀបរក្សាទុកច្បាប់ចម្លង (Fork) គម្រោងរបស់អ្នកឱ្យទាន់សម័យជាមួយនឹងគម្រោងដើម (Upstream Repository) ផងដែរ។

### ៥.១. ការបំបែកគម្រោង (Forking)

**Forking** គឺជាដំណើរការនៃការបង្កើតច្បាប់ចម្លងផ្ទាល់ខ្លួនរបស់អ្នកនៃ Repository របស់អ្នកដទៃទៅក្នុងគណនី GitHub ផ្ទាល់ខ្លួនរបស់អ្នក។ វាប្រៀបដូចជាការថតចម្លង (Copy) គម្រោងដើមទៅក្នុងគណនីរបស់អ្នក ដែលអនុញ្ញាតឱ្យអ្នកធ្វើការផ្លាស់ប្តូរដោយសេរី ដោយមិនប៉ះពាល់ដល់ Repository ដើមឡើយ។

#### ហេតុអ្វីត្រូវ Fork?

*   **ចូលរួមចំណែកក្នុងគម្រោងសាធារណៈ (Contributing to Open Source)**: នេះគឺជាវិធីសាស្ត្រស្តង់ដារដើម្បីចូលរួមចំណែកក្នុងគម្រោង Open Source ។ តាមរយៈការ Fork អ្នកអាចធ្វើការផ្លាស់ប្តូរនៅក្នុង Fork ផ្ទាល់ខ្លួនរបស់អ្នក រួចស្នើសុំឱ្យបញ្ចូលការផ្លាស់ប្តូររបស់អ្នកទៅក្នុង Repository ដើមវិញ (តាមរយៈ Pull Request)។ នេះរក្សានូវ Repository ដើមឱ្យមានសុវត្ថិភាពពីការផ្លាស់ប្តូរដោយផ្ទាល់ពីអ្នករួមចំណែកខាងក្រៅ។
*   **បង្កើតច្បាប់ចម្លងផ្ទាល់ខ្លួន (Personal Copy)**: អ្នកអាច Fork Repository មួយដើម្បីរក្សាទុកកំណែផ្ទាល់ខ្លួនរបស់អ្នក (ឧទាហរណ៍ អ្នកចង់កែប្រែគម្រោងនោះសម្រាប់គោលបំណងផ្ទាល់ខ្លួន) ឬប្រើប្រាស់វាជាចំណុចចាប់ផ្តើមសម្រាប់គម្រោងថ្មីមួយ។
*   **ការពិសោធន៍ (Experimentation)**: អ្នកអាចពិសោធន៍ជាមួយ Code របស់គម្រោងដើមនៅក្នុង Fork របស់អ្នកដោយមិនចាំបាច់បារម្ភពីការបំផ្លាញគម្រោងដើម។

#### របៀប Fork Repository:

1.  ចូលទៅកាន់ Repository នៅលើ GitHub ដែលអ្នកចង់ Fork (ឧទាហរណ៍ `https://github.com/octocat/Spoon-Knife`)។
2.  ចុចលើប៊ូតុង **"Fork"** នៅជ្រុងខាងស្តាំខាងលើនៃទំព័រ។
3.  GitHub នឹងបង្កើតច្បាប់ចម្លងនៃ Repository នោះទៅក្នុងគណនីរបស់អ្នក។ អ្នកអាចនឹងត្រូវបានសួរឱ្យជ្រើសរើស Owner សម្រាប់ Fork (ប្រសិនបើអ្នកមាន Organizations ជាច្រើន) និងផ្តល់ការពិពណ៌នាស្រេចចិត្ត។

![GitHub Fork](https://i.imgur.com/L1MhG4m.png)
*រូបភាពទី ៥.១៖ ប៊ូតុង Fork នៅលើ GitHub*

បន្ទាប់ពី Forking រួច អ្នកនឹងមាន Repository ផ្ទាល់ខ្លួនរបស់អ្នក (ឧទាហរណ៍ `yourusername/Spoon-Knife`) ដែលជាច្បាប់ចម្លងនៃ Repository ដើម។ ឥឡូវអ្នកអាច Clone Fork របស់អ្នកទៅ Local Computer របស់អ្នក ហើយចាប់ផ្តើមធ្វើការ។

### ៥.២. ការស្នើសុំបញ្ចូល Code (Pull Requests - PRs)

**Pull Request (PR)** គឺជាសំណើដែលអ្នកផ្ញើទៅកាន់ម្ចាស់ Repository ដើម ដើម្បីស្នើសុំឱ្យពួកគេពិនិត្យមើល និងបញ្ចូល (Merge) ការផ្លាស់ប្តូរ Code របស់អ្នកទៅក្នុង Repository របស់ពួកគេ។ PRs គឺជាបេះដូងនៃការសហការគ្នានៅលើ GitHub ជាពិសេសនៅក្នុងគម្រោង Open Source និងក្រុមអភិវឌ្ឍន៍។

#### Workflow របស់ Pull Request (ជំហានលម្អិត):

1.  **Fork the Repository**: ដូចដែលបានរៀបរាប់ខាងលើ អ្នក Fork Repository ដើមទៅក្នុងគណនី GitHub ផ្ទាល់ខ្លួនរបស់អ្នក។

2.  **Clone the Fork**: Clone Fork របស់អ្នកទៅកាន់ Local Computer ។ នេះបង្កើត Remote `origin` ដែលចង្អុលទៅ Fork របស់អ្នក។
    ```bash
git clone https://github.com/yourusername/forked-repo.git
    ```

3.  **Add Upstream Remote (ស្រេចចិត្ត តែត្រូវបានណែនាំ)**: ដើម្បីអាចទាញយកការផ្លាស់ប្តូរពី Repository ដើម (Upstream) អ្នកគួរតែកំណត់ Remote មួយសម្រាប់វា។
    ```bash
cd forked-repo
git remote add upstream https://github.com/original-owner/original-repo.git
    ```
    *   `origin`: ចង្អុលទៅ Fork របស់អ្នក (repository ផ្ទាល់ខ្លួនរបស់អ្នក)
    *   `upstream`: ចង្អុលទៅ repository ដើម (repository ដែលអ្នកបាន fork)

4.  **Create a New Branch**: មុនពេលធ្វើការផ្លាស់ប្តូរណាមួយ ត្រូវប្រាកដថាអ្នកនៅ Branch `main` (ឬ `master`) របស់ Fork របស់អ្នក ហើយទាញយក Update ចុងក្រោយពី `upstream` ។ បន្ទាប់មកបង្កើត Branch ថ្មីមួយសម្រាប់ Feature ឬ Bug Fix របស់អ្នក។ នេះរក្សាទុក Branch `main` របស់អ្នកឱ្យស្អាត។
    ```bash
git checkout main
git pull upstream main # ទាញ Update ពី repository ដើម
git push origin main   # Push Update ទៅ Fork របស់អ្នក
git checkout -b feature/my-new-feature
    ```

5.  **Make Changes and Commit**: ធ្វើការផ្លាស់ប្តូរ Code របស់អ្នក ហើយ Commit ពួកវាទៅកាន់ Branch ថ្មី។ ត្រូវប្រាកដថា Commit Message របស់អ្នកច្បាស់លាស់ និងមានអត្ថន័យ។
    ```bash
git add .
git commit -m "Implement my new feature for issue #123"
    ```

6.  **Push Changes to Your Fork**: Push Branch ថ្មីរបស់អ្នកទៅកាន់ Fork របស់អ្នកនៅលើ GitHub ។
    ```bash
git push origin feature/my-new-feature
    ```

7.  **Create a Pull Request**: ចូលទៅកាន់ GitHub Repository នៃ Fork របស់អ្នក។ GitHub នឹងបង្ហាញប៊ូតុង **"Compare & pull request"** នៅខាងលើ។ ចុចលើវាដើម្បីបង្កើត PR។
    *   **ជ្រើសរើស Base and Head**: ត្រូវប្រាកដថា Base repository គឺជា repository ដើម ហើយ Head repository គឺជា Fork របស់អ្នកជាមួយ Branch ដែលអ្នកបានធ្វើការ។
    *   **ផ្តល់ចំណងជើង និងការពិពណ៌នាលម្អិត**: ចំណងជើងគួរតែខ្លី ច្បាស់លាស់។ ការពិពណ៌នាគួរតែពន្យល់ពី "ហេតុអ្វី" និង "អ្វី" ដែលអ្នកបានធ្វើ គុណសម្បត្តិ និងគុណវិបត្តិ (ប្រសិនបើមាន) និងឯកសារយោងទៅ Issue (ប្រសិនបើមាន)។
    *   GitHub នឹងបង្ហាញពីភាពខុសគ្នានៃ Code (Diff) រវាង Branch របស់អ្នក និង Branch ដើម ដែលអនុញ្ញាតឱ្យអ្នកពិនិត្យមើលការផ្លាស់ប្តូររបស់អ្នក។

![GitHub Pull Request](https://i.imgur.com/Q2h3G6m.png)
*រូបភាពទី ៥.២៖ ការបង្កើត Pull Request*

8.  **Code Review**: ម្ចាស់ Repository ដើម និងសមាជិកក្រុមផ្សេងទៀតនឹងពិនិត្យមើល Code របស់អ្នក ផ្តល់យោបល់ និងស្នើសុំការកែប្រែ (ប្រសិនបើចាំបាច់)។ អ្នកអាចឆ្លើយតបទៅនឹងមតិយោបល់ និងធ្វើការកែប្រែបន្ថែមដោយ Push Commits ថ្មីទៅកាន់ Branch របស់អ្នក។

9.  **Merge the Pull Request**: នៅពេលដែល Code ត្រូវបានពិនិត្យ ឆ្លងកាត់ការតេស្ត (CI/CD) និងយល់ព្រម ម្ចាស់ Repository នឹង Merge PR របស់អ្នកទៅក្នុង Branch ដើម (ជាធម្មតា `main` ឬ `master`)។ GitHub ផ្តល់នូវជម្រើស Merge មួយចំនួនដូចជា:
    *   **Create a merge commit**: រក្សាទុកប្រវត្តិ Branch ទាំងពីរ។
    *   **Squash and merge**: បង្រួម Commits ទាំងអស់របស់ PR ទៅជា Commit តែមួយនៅក្នុង Base Branch។ ល្អសម្រាប់រក្សាប្រវត្តិឱ្យស្អាត។
    *   **Rebase and merge**: អនុវត្ត Commits របស់ PR ទៅលើ Base Branch ដោយលុប Merge Commit ចោល។

### ៥.៣. ការគ្រប់គ្រងបញ្ហា (Issues)

**Issues** នៅលើ GitHub គឺជាឧបករណ៍តាមដានសម្រាប់កិច្ចការ ការកែលម្អ លក្ខណៈពិសេសថ្មីៗ ឬ Bug ។ វាជាកន្លែងកណ្តាលសម្រាប់ពិភាក្សា និងរៀបចំផែនការការងាររបស់គម្រោង។ Issues ជួយរៀបចំការងារ និងធានាថាគ្មានកិច្ចការណាត្រូវបានមើលរំលងឡើយ។

#### ការប្រើប្រាស់ Issues:

*   **រាយការណ៍ Bugs**: ប្រសិនបើអ្នករកឃើញ Bug នៅក្នុងគម្រោង អ្នកអាចបង្កើត Issue ដើម្បីរាយការណ៍វា។ ត្រូវផ្តល់ព័ត៌មានលម្អិតដូចជា របៀប Reproduce Bug, អ្វីដែលអ្នករំពឹងទុក និងអ្វីដែលបានកើតឡើងពិតប្រាកដ។
*   **ស្នើសុំលក្ខណៈពិសេស (Feature Requests)**: អ្នកអាចស្នើសុំ Feature ថ្មីដោយបង្កើត Issue។ ពន្យល់ពីតម្រូវការ និងគុណសម្បត្តិនៃ Feature នោះ។
*   **ការតាមដានកិច្ចការ (Task Tracking)**: ប្រើ Issues ដើម្បីតាមដានកិច្ចការសម្រាប់ខ្លួនឯង ឬ Assign ទៅសមាជិកក្រុមផ្សេងទៀត។
*   **ការពិភាក្សា (Discussions)**: ពិភាក្សាអំពីការផ្លាស់ប្តូរ Code ឬគំនិតថ្មីៗមុននឹងចាប់ផ្តើមសរសេរ Code ។
*   **ការរៀបចំផែនការ (Planning)**: អាចត្រូវបានប្រើជាផ្នែកមួយនៃ Process នៃការរៀបចំផែនការ Sprint ឬ Milestone។

#### របៀបបង្កើត Issue:

1.  ចូលទៅកាន់ Repository នៅលើ GitHub ។
2.  ចុចលើផ្ទាំង **"Issues"** ។
3.  ចុចលើប៊ូតុង **"New issue"** ។
4.  **ជ្រើសរើស Template**: Repository មួយចំនួនអាចមាន Issue templates សម្រាប់ Bug reports ឬ Feature requests ដែលជួយណែនាំអ្នកឱ្យផ្តល់ព័ត៌មានត្រឹមត្រូវ។
5.  **ផ្តល់ចំណងជើង និងការពិពណ៌នាលម្អិត**: ចំណងជើងគួរតែជាសេចក្តីសង្ខេប ច្បាស់លាស់។ ការពិពណ៌នាគួរតែពន្យល់ពីបញ្ហា ឬសំណើឱ្យបានលម្អិត។
6.  **បន្ថែម Metadata (ស្រេចចិត្ត)**:
    *   **Assignees**: Assign Issue ទៅនរណាម្នាក់ (ជាធម្មតាអ្នកដែលទទួលខុសត្រូវលើកិច្ចការនោះ)។
    *   **Labels**: បន្ថែម Labels (ស្លាក) ដើម្បីចាត់ថ្នាក់ Issue របស់អ្នក (ឧទាហរណ៍ `bug`, `enhancement`, `documentation`, `help wanted`)។
    *   **Projects**: Add Issue ទៅ Project (សម្រាប់ Project Management)។
    *   **Milestones**: កំណត់ Milestone សម្រាប់ Issue (សម្រាប់ Tracking Progress ឆ្ពោះទៅកាន់ Version ជាក់លាក់)។
7.  ចុច **"Submit new issue"** ។

![GitHub Issues](https://i.imgur.com/G5qW0S9.png)
*រូបភាពទី ៥.៣៖ ការបង្កើត Issue ថ្មីនៅលើ GitHub*

### ៥.៤. ការរក្សា Fork របស់អ្នកឱ្យទាន់សម័យ (Syncing a Fork)

ប្រសិនបើ Repository ដើម (Upstream) មានការផ្លាស់ប្តូរថ្មី អ្នកនឹងចង់ Sync Fork របស់អ្នកជាមួយវា ដើម្បីឱ្យ Fork របស់អ្នកទាន់សម័យ។ នេះជាការចាំបាច់ដើម្បីឱ្យការងាររបស់អ្នកមានមូលដ្ឋានលើ Code ចុងក្រោយបំផុតរបស់គម្រោងដើម និងជៀសវាង Merge Conflicts ធំៗ។

#### ជំហានដើម្បី Sync Fork របស់អ្នក:

1.  **បន្ថែម Remote សម្រាប់ Upstream Repository**: ប្រសិនបើអ្នកមិនទាន់បានធ្វើវាទេ អ្នកត្រូវប្រាប់ Git អំពី Repository ដើម។
    ```bash
    # បើក Terminal នៅក្នុង Local Clone នៃ Fork របស់អ្នក
    # បន្ថែម remote មួយឈ្មោះ 'upstream' ដែលសំដៅទៅ repository ដើម
git remote add upstream https://github.com/original-owner/original-repo.git
    ```
    អ្នកអាចពិនិត្យមើល remotes របស់អ្នកដោយ `git remote -v` ។ អ្នកគួរតែឃើញ `origin` (Fork របស់អ្នក) និង `upstream` (repository ដើម)។

2.  **Fetch Changes from Upstream**: ទាញយកការផ្លាស់ប្តូរថ្មីៗពី Repository ដើម។ នេះនឹងទាញយក Branch ទាំងអស់របស់ Upstream ទៅ Local របស់អ្នក ប៉ុន្តែវាមិន Merge ពួកវាទៅក្នុង Local Branches របស់អ្នកដោយស្វ័យប្រវត្តិទេ។
    ```bash
git fetch upstream
    ```

3.  **Checkout Your Local Base Branch**: ប្តូរទៅ Branch ក្នុងស្រុករបស់អ្នកដែលអ្នកចង់ Update (ជាធម្មតា `main` ឬ `master`)
    ```bash
git checkout main
    ```

4.  **Merge Upstream Changes**: ច្របាច់បញ្ចូលគ្នានូវការផ្លាស់ប្តូរពី `upstream/main` ទៅក្នុង Local `main` Branch របស់អ្នក។
    ```bash
git merge upstream/main
    ```
    *   **ចំណាំ**: ប្រសិនបើអ្នកចង់រក្សាប្រវត្តិឱ្យស្អាត អ្នកអាចប្រើ `git rebase upstream/main` ជំនួស `git merge`។ ទោះជាយ៉ាងណាក៏ដោយ សូមប្រយ័ត្នចំពោះការ Rebase ប្រសិនបើអ្នកបាន Push Local Branch របស់អ្នករួចហើយ។

5.  **Push Changes to Your Fork**: Push ការផ្លាស់ប្តូរដែលបាន Merge (ឬ Rebase) ទៅកាន់ Fork របស់អ្នកនៅលើ GitHub ។ នេះធ្វើឱ្យ Fork របស់អ្នកទាន់សម័យជាមួយ Upstream ។
    ```bash
git push origin main
    ```

### ៥.៥. លំហាត់អនុវត្ត

1.  ទៅកាន់ Repository មួយចំនួននៅលើ GitHub ដែលអ្នកចាប់អារម្មណ៍ (ឧទាហរណ៍ [https://github.com/freeCodeCamp/freeCodeCamp](https://github.com/freeCodeCamp/freeCodeCamp)) ហើយ **Fork** វាទៅក្នុងគណនីរបស់អ្នក។
2.  **Clone** Fork របស់អ្នកទៅកាន់ Local Computer របស់អ្នក។
    ```bash
git clone https://github.com/yourusername/forked-repository-name.git
    ```
    *   ត្រូវប្រាកដថាអ្នកជំនួស `yourusername` និង `forked-repository-name` ជាមួយនឹងព័ត៌មានត្រឹមត្រូវ។

3.  **បន្ថែម Upstream Remote**: នៅក្នុង Local Clone របស់អ្នក បន្ថែម Remote សម្រាប់ Repository ដើម។
    ```bash
cd forked-repository-name
git remote add upstream https://github.com/original-owner/original-repository-name.git
    ```
    *   អ្នកអាចរកឃើញ `original-owner` និង `original-repository-name` ពី URL របស់ Repository ដើម។

4.  បង្កើត Branch ថ្មីមួយ (ឧទាហរណ៍ `feature/my-first-contribution`)។
    ```bash
git checkout -b feature/my-first-contribution
    ```

5.  ធ្វើការផ្លាស់ប្តូរសាមញ្ញមួយចំនួននៅក្នុង Local Repository របស់អ្នក (ឧទាហរណ៍ កែសម្រួលឯកសារ `README.md` បន្តិចបន្តួច ឬបន្ថែម File ថ្មីមួយ)។

6.  Add និង Commit ការផ្លាស់ប្តូរទាំងនោះ។
    ```bash
git add .
git commit -m "My first minor change: update README"
    ```

7.  **Push** Branch របស់អ្នកទៅកាន់ Fork របស់អ្នកនៅលើ GitHub ។
    ```bash
git push origin feature/my-first-contribution
    ```

8.  ចូលទៅកាន់ Fork របស់អ្នកនៅលើ GitHub ហើយបង្កើត **Pull Request** មួយទៅកាន់ Repository ដើម។ សរសេរសារពិពណ៌នាសមរម្យសម្រាប់ PR របស់អ្នក (ឧទាហរណ៍ "Adds a small correction to README").
    *   **ចំណាំ**: សម្រាប់លំហាត់នេះ អ្នកមិនចាំបាច់រំពឹងថា PR របស់អ្នកត្រូវបាន Merge ទេ។ គោលបំណងគឺដើម្បីអនុវត្តដំណើរការនេះ។

9.  ត្រឡប់ទៅ Repository ដើម (មិនមែន Fork របស់អ្នកទេ) ហើយស្វែងរកផ្ទាំង **Issues** ។ ព្យាយាមបង្កើត Issue ថ្មីមួយ (ឧទាហរណ៍ "Improve documentation for X feature") ដើម្បីយល់ពីរបៀបដែលវាដំណើរការ។

10. (ជម្រើស) **អនុវត្តការ Sync តាមរយៈ GitHub Web UI**: GitHub ថ្មីៗនេះបានបន្ថែមមុខងារ "Fetch upstream" និង "Sync fork" ដោយផ្ទាល់នៅលើទំព័រ Fork របស់អ្នក។ ចូលទៅកាន់ Fork របស់អ្នកនៅលើ GitHub ហើយសាកល្បងប្រើប៊ូតុងទាំងនេះ ដើម្បីមើលពីរបៀបដែលវារក្សា Fork របស់អ្នកឱ្យទាន់សម័យដោយមិនចាំបាច់ប្រើ Command Line។

11. (ជម្រើស) **Sync Fork របស់អ្នកពី Command Line**: ប្រសិនបើមានការផ្លាស់ប្តូរថ្មីនៅក្នុង Repository ដើម (Upstream) សូមអនុវត្តជំហាននៅក្នុងផ្នែក ៥.៤ ដើម្បី Sync Local Fork របស់អ្នក ហើយបន្ទាប់មក Push ការផ្លាស់ប្តូរទាំងនោះទៅ Fork របស់អ្នកនៅលើ GitHub ។

## ជំពូកទី ៦: បច្ចេកទេស Git កម្រិតខ្ពស់ (Stash, Rebase, Reset vs Revert)

នៅក្នុងជំពូកចុងក្រោយនេះ យើងនឹងស្វែងយល់ពីពាក្យបញ្ជា Git កម្រិតខ្ពស់មួយចំនួន ដែលអាចជួយឱ្យការងាររបស់អ្នកកាន់តែមានប្រសិទ្ធភាព និងគ្រប់គ្រងប្រវត្តិ Repository បានល្អប្រសើរ។ ការយល់ដឹងពីបច្ចេកទេសទាំងនេះនឹងអនុញ្ញាតឱ្យអ្នកដោះស្រាយស្ថានភាពស្មុគស្មាញ និងរក្សាប្រវត្តិគម្រោងរបស់អ្នកឱ្យមានរបៀបរៀបរយ។

### ៦.១. ការរក្សាទុកការផ្លាស់ប្តូរបណ្តោះអាសន្ន (`git stash`)

ជួនកាល អ្នកកំពុងធ្វើការលើ Feature មួយ ប៉ុន្តែភ្លាមៗអ្នកត្រូវប្តូរទៅធ្វើការលើ Bug Fix វិញ។ បញ្ហាគឺថា អ្នកមិនទាន់ចង់ Commit ការផ្លាស់ប្តូររបស់អ្នកទៅលើ Feature នោះទេ ហើយការប្តូរទៅ Branch ផ្សេងខណៈពេលដែលមានការផ្លាស់ប្តូរដែលមិនទាន់បាន Commit អាចធ្វើឱ្យ Git បង្ហាញ Error ឬបណ្តាលឱ្យមានបញ្ហា។ ក្នុងករណីនេះ `git stash` មានប្រយោជន៍ណាស់។

`git stash` យកការផ្លាស់ប្តូរដែលមិនទាន់បាន Commit របស់អ្នក (ទាំង Staged និង Unstaged) ហើយរក្សាទុកវាបណ្តោះអាសន្នទៅក្នុង "Stack of Stashes" (ជង់) ដោយបន្សល់ទុក Working Directory របស់អ្នកឱ្យស្អាតដូច Commit ចុងក្រោយ។

#### ៦.១.១. ការប្រើប្រាស់មូលដ្ឋាន:

*   **`git stash` ឬ `git stash push`**: រក្សាទុកការផ្លាស់ប្តូរបណ្តោះអាសន្ន។ វារក្សាទុកទាំង `staged` និង `unstaged` changes។
    ```bash
    # ធ្វើការផ្លាស់ប្តូរខ្លះៗទៅលើឯកសារ A និង B
    # git add A (ឯកសារ A ត្រូវបាន Staged, B មិនទាន់)
    git stash
    # Working Directory របស់អ្នកឥឡូវស្អាតហើយ (ឯកសារ A និង B ត្រូវបាន Stashed)
    ```
    អ្នកក៏អាចបន្ថែមសារសម្រាប់ stash របស់អ្នក ដើម្បីជួយចងចាំថាវាសម្រាប់អ្វី:
    ```bash
    git stash push -m "Working on user registration feature"
    ```

*   **`git stash list`**: បង្ហាញបញ្ជី Stash ដែលបានរក្សាទុកទាំងអស់។ Stashes ត្រូវបានដាក់ឈ្មោះតាមលំដាប់ `stash@{0}`, `stash@{1}` ជាដើម។
    ```
    stash@{0}: On main: Working on user registration feature
    stash@{1}: On feature/new-design: Add header component
    ```

*   **`git stash show`**: បង្ហាញព័ត៌មានលម្អិតអំពី Stash ចុងក្រោយ (stash@{0})។
    *   `git stash show -p`: បង្ហាញ Diff ពេញលេញនៃការផ្លាស់ប្តូរនៅក្នុង Stash ចុងក្រោយ។
    *   `git stash show stash@{1}`: បង្ហាញព័ត៌មានលម្អិតរបស់ Stash ជាក់លាក់។

*   **`git stash apply [stash@{n}]`**: អនុវត្ត Stash ណាមួយ (ឬ Stash ចុងក្រោយ ប្រសិនបើមិនបញ្ជាក់) ទៅ Working Directory របស់អ្នកឡើងវិញ ប៉ុន្តែ **មិនលុបវាចេញពីបញ្ជី Stash ទេ**។ នេះអនុញ្ញាតឱ្យអ្នកអនុវត្ត Stash ដដែលទៅ Branch ច្រើនដង។
    ```bash
    git stash apply
    # ឬអនុវត្ត stash ជាក់លាក់
    git stash apply stash@{1}
    ```

*   **`git stash pop [stash@{n}]`**: អនុវត្ត Stash ណាមួយ (ឬ Stash ចុងក្រោយ) ទៅ Working Directory របស់អ្នកឡើងវិញ ហើយ **លុបវាចេញពីបញ្ជី Stash តែម្តង**។ នេះជាទូទៅត្រូវបានគេប្រើនៅពេលអ្នកបានបញ្ចប់ការប្រើប្រាស់ Stash នោះ។
    ```bash
    git stash pop
    ```

*   **`git stash drop [stash@{n}]`**: លុប Stash ជាក់លាក់មួយចេញពីបញ្ជី (ដោយមិនអនុវត្តវា)។
    ```bash
    git stash drop stash@{1}
    ```

*   **`git stash clear`**: លុប Stash ទាំងអស់ចេញពីបញ្ជី។

#### ៦.១.២. ករណីប្រើប្រាស់:

*   **ប្តូរ Branch លឿន**: ពេលអ្នកកំពុងធ្វើការលើ Branch មួយ ហើយត្រូវប្តូរទៅ Branch ផ្សេងដើម្បីជួសជុល Bug ភ្លាមៗ អ្នកអាច Stash ការងារបច្ចុប្បន្នរបស់អ្នក ប្តូរ Branch ជួសជុល Bug រួចត្រឡប់មកវិញ ហើយ `stash pop` ការងាររបស់អ្នកវិញ។
*   **សម្អាត Working Directory**: ពេលអ្នកមានការផ្លាស់ប្តូរជាច្រើននៅក្នុង Working Directory ប៉ុន្តែអ្នកចង់ចាប់ផ្តើមពីចំណុចស្អាត អ្នកអាច Stash វា ហើយអនុវត្តវាវិញនៅពេលក្រោយ។

### ៦.២. ការរៀបចំប្រវត្តិ Commit (`git rebase`)

**Rebase** គឺជាពាក្យបញ្ជាដ៏មានអានុភាពមួយសម្រាប់ផ្លាស់ប្តូរប្រវត្តិ Commit។ វាយក Commits ពី Branch មួយ ហើយអនុវត្តវាទៅលើ Branch មួយទៀតក្នុងលំដាប់លីនេអ៊ែរ (Linear fashion) ដោយផ្លាស់ប្តូរ Base (មូលដ្ឋាន) នៃ Branch នោះ។

#### ហេតុអ្វីត្រូវ Rebase?

*   **រក្សាប្រវត្តិឱ្យស្អាត (Clean, Linear History)**: Rebase អាចជួយរក្សាប្រវត្តិគម្រោងរបស់អ្នកឱ្យមានលក្ខណៈ Linear និងស្អាត ដោយជៀសវាង Merge Commits ជាច្រើន ដែលធ្វើឱ្យប្រវត្តិមានភាពស្មុគស្មាញ និងពិបាកអាន។
*   **បញ្ចូលការផ្លាស់ប្តូរពី Branch មេ**: ប្រសិនបើអ្នកកំពុងធ្វើការលើ Feature Branch ហើយ Branch មេ (`main` ឬ `master`) មានការផ្លាស់ប្តូរថ្មីៗ អ្នកអាច Rebase Feature Branch របស់អ្នកទៅលើ `main` ដើម្បីឱ្យ Feature Branch របស់អ្នកទាន់សម័យជាមួយ Code ចុងក្រោយបំផុតមុនពេល Merge។ នេះកាត់បន្ថយ Merge Conflicts នៅពេល Merge ចុងក្រោយ។

#### ៦.២.១. ឧទាហរណ៍ការប្រើប្រាស់ Rebase:

ឧបមាថាអ្នកមាន `main` Branch និង `feature` Branch ។

```
A -- B -- C (main)
      \
       D -- E (feature)
```

ហើយ `main` ត្រូវបាន Update ដោយ Commit ថ្មី `F`:

```
A -- B -- C -- F (main)
      \
       D -- E (feature)
```

**ករណីទី ១: `git merge feature` ទៅ `main` (ពី Branch `main`)**
```bash
git checkout main
git merge feature
```
អ្នកនឹងឃើញ Merge Commit `G`:
```
A -- B -- C -- F -- G (main)
      \           /
       D -- E --
          (feature)
```
*   **គុណសម្បត្តិ**: រក្សាទុកប្រវត្តិពិតប្រាកដនៃ Branching និង Merging ។
*   **គុណវិបត្តិ**: ប្រវត្តិអាចមើលទៅរញ៉េរញ៉ៃបន្តិចបន្តួចនៅពេលមាន Merge Commits ច្រើន។

**ករណីទី ២: `git rebase main` (ពី Branch `feature`)**

1.  **`git checkout feature`**
2.  **`git rebase main`**

Git នឹងដក Commit `D` និង `E` ចេញជាបណ្តោះអាសន្ន ដាក់ `feature` នៅលើ `F` (ជា Base ថ្មី) រួចអនុវត្ត `D` និង `E` ឡើងវិញ។ លទ្ធផល:

```
A -- B -- C -- F -- D' -- E' (feature)
                 ^
                 | (main)
```
*   `D'` និង `E'` គឺជា Commits ថ្មីដែលមានមាតិកាដូច `D` និង `E` ប៉ុន្តែមាន Hash ID ខុសគ្នា ព្រោះវាត្រូវបានបង្កើតឡើងវិញនៅលើ Base ថ្មី។

បន្ទាប់មក អ្នកអាចត្រឡប់ទៅ `main` ហើយ `git merge feature` (វានឹងក្លាយជា Fast-Forward Merge):

```bash
git checkout main
git merge feature
```

លទ្ធផល:

```
A -- B -- C -- F -- D' -- E' (main, feature)
```

*   **គុណសម្បត្តិ**: ប្រវត្តិរបស់អ្នកឥឡូវមើលទៅស្អាត និង Linear ដែលងាយស្រួលអាន។
*   **គុណវិបត្តិ**: ផ្លាស់ប្តូរ Hash ID នៃ Commits (D, E ក្លាយជា D', E') ដែលអាចមានបញ្ហាបើ Commits ទាំងនោះត្រូវបាន Push រួចហើយ។

#### ៦.២.២. Rebase អន្តរកម្ម (`git rebase -i`)

`git rebase -i <commit-hash-or-ref>` (interactive rebase) អនុញ្ញាតឱ្យអ្នកផ្លាស់ប្តូរប្រវត្តិ Commit កាន់តែលម្អិត។ `<commit-hash-or-ref>` គឺសំដៅទៅ Commit ដែលអ្នកចង់ឱ្យ Rebase ចាប់ផ្តើមពី។ ឧទាហរណ៍ `HEAD~3` មានន័យថា 3 Commits ចុងក្រោយពី `HEAD` ។

```bash
git rebase -i HEAD~3
```

នេះនឹងបើក Editor ដែលបង្ហាញ 3 Commits ចុងក្រោយ ហើយអនុញ្ញាតឱ្យអ្នកកែប្រែពួកវាដោយប្រើពាក្យបញ្ជាខាងក្រោម:

*   **`pick`**: រក្សា Commit ដូចធម្មតា។
*   **`reword`**: ផ្លាស់ប្តូរសារ Commit។
*   **`edit`**: ឈប់នៅ Commit ជាក់លាក់មួយដើម្បីកែសម្រួលវា (ឧទាហរណ៍ បន្ថែម File ភ្លេច)។
*   **`squash`**: បញ្ចូល Commit បច្ចុប្បន្នជាមួយ Commit មុន។ Git នឹងសុំឱ្យអ្នកបញ្ចូលសារ Commit ទាំងពីរទៅជាសារតែមួយ។
*   **`fixup`**: បញ្ចូល Commit បច្ចុប្បន្នជាមួយ Commit មុន ប៉ុន្តែបោះបង់សារ Commit របស់ Commit បច្ចុប្បន្ន (ប្រើសារ Commit មុន)។
*   **`drop`**: លុប Commit ចោល។
*   **`merge`**: (កម្រប្រើ) បញ្ចូល Commit ចូលទៅក្នុង Parent Commit របស់វា។

**ឧទាហរណ៍ `squash`:**

ប្រសិនបើអ្នកមាន Commits ដូចនេះ:
```
feature-branch: A -- B -- C -- D
```
ហើយអ្នកចង់បញ្ចូល B, C, D ទៅជា Commit តែមួយ ដោយរក្សាទុក A ។
អ្នកអាចរត់ `git rebase -i A` (ឬ `git rebase -i HEAD~3` ប្រសិនបើ A ជា 3rd commit ពី HEAD)

```
pick A Initial commit
squash B Add feature part 1
squash C Fix bug in feature
squash D Complete feature
```
លទ្ធផលនឹងជា `A -- BCD'` (BCD' គឺជា Commit ថ្មីដែលរួមបញ្ចូល B, C, D)

**ការប្រុងប្រយ័ត្ន**: **កុំ Rebase Commits ដែលត្រូវបាន Push ទៅ Remote Repository រួចហើយ** ប្រសិនបើអ្នកកំពុងធ្វើការជាមួយអ្នកដទៃ។ ការធ្វើបែបនេះអាចបណ្តាលឱ្យមានបញ្ហាសម្រាប់អ្នកសហការផ្សេងទៀត ព្រោះវាផ្លាស់ប្តូរប្រវត្តិសាស្រ្តដែលបានចែករំលែក។ Rebase ល្អបំផុតសម្រាប់ Local Commits ដែលមិនទាន់បានចែករំលែក។

### ៦.៣. ការកែប្រែប្រវត្តិ (`git reset` vs `git revert`)

ទាំង `git reset` និង `git revert` ត្រូវបានប្រើដើម្បីបោះបង់ការផ្លាស់ប្តូរ ប៉ុន្តែពួកគេធ្វើវាខុសគ្នា និងសម្រាប់សេណារីយ៉ូផ្សេងគ្នា។ ការយល់ដឹងពីភាពខុសគ្នានេះគឺសំខាន់ណាស់ដើម្បីជៀសវាងការបំផ្លាញប្រវត្តិគម្រោង។

#### ៦.៣.១. `git reset` (Rewrites history - potentially dangerous)

`git reset` ផ្លាស់ទី HEAD Pointer ទៅកាន់ Commit ផ្សេងទៀត ហើយអាចផ្លាស់ប្តូរប្រវត្តិ Commit ។ វាមានរបៀបជាច្រើន ដែលកំណត់ថាតើវាប៉ះពាល់ដល់ Working Directory និង Staging Area របស់អ្នកយ៉ាងដូចម្តេច:

*   **`git reset --soft <commit>`**:
    *   **HEAD Pointer**: ផ្លាស់ទី HEAD Pointer ទៅកាន់ `<commit>` ដែលបានកំណត់។
    *   **Staging Area**: រក្សាទុកការផ្លាស់ប្តូរទាំងអស់ដែលបានធ្វើឡើងចាប់តាំងពី `<commit>` នោះនៅក្នុង Staging Area (ពួកវាត្រូវបាន Staged រួចរាល់សម្រាប់ Commit ម្តងទៀត)។
    *   **Working Directory**: មិនមានការផ្លាស់ប្តូរអ្វីទាំងអស់។
    *   **ករណីប្រើប្រាស់**: ល្អនៅពេលអ្នកបានធ្វើ Commit ច្រើនពេក ហើយចង់បញ្ចូលពួកវាទៅជា Commit តែមួយ ដោយរក្សាការផ្លាស់ប្តូរទាំងអស់ Staged ។

*   **`git reset --mixed <commit>` (Default)**:
    *   **HEAD Pointer**: ផ្លាស់ទី HEAD Pointer ទៅកាន់ `<commit>` ដែលបានកំណត់។
    *   **Staging Area**: ដកការផ្លាស់ប្តូរទាំងអស់ដែលបានធ្វើឡើងចាប់តាំងពី `<commit>` នោះចេញពី Staging Area (ពួកវាត្រូវបាន Unstaged)។
    *   **Working Directory**: មិនមានការផ្លាស់ប្តូរអ្វីទាំងអស់។ ការផ្លាស់ប្តូរទាំងនោះនៅតែមាននៅក្នុង Working Directory របស់អ្នកជា `Modified` files។
    *   **ករណីប្រើប្រាស់**: ល្អនៅពេលអ្នកបានធ្វើ Commit ដែលមិនពេញចិត្ត ឬចង់រៀបចំ Commits ឡើងវិញ ដោយចាប់ផ្តើមពីស្ថានភាពដែលការផ្លាស់ប្តូរទាំងអស់ត្រូវបាន Unstaged ។

*   **`git reset --hard <commit>`**:
    *   **HEAD Pointer**: ផ្លាស់ទី HEAD Pointer ទៅកាន់ `<commit>` ដែលបានកំណត់។
    *   **Staging Area**: លុបការផ្លាស់ប្តូរទាំងអស់ដែលបានធ្វើឡើងចាប់តាំងពី `<commit>` នោះចេញពី Staging Area ។
    *   **Working Directory**: **លុបចោលរាល់ការផ្លាស់ប្តូរទាំងអស់** (ទាំង Staged និង Unstaged) ចេញពី Working Directory របស់អ្នក ដែលបានធ្វើឡើងចាប់តាំងពី `<commit>` នោះ។ **នេះជាពាក្យបញ្ជាដ៏គ្រោះថ្នាក់បំផុត** ព្រោះវាអាចបណ្តាលឱ្យបាត់បង់ការងារដែលមិនបាន Commit ជាអចិន្ត្រៃយ៍។
    *   **ករណីប្រើប្រាស់**: ប្រើនៅពេលអ្នកចង់បោះបង់ការផ្លាស់ប្តូរទាំងអស់ទាំងស្រុង ហើយត្រឡប់ Working Directory និង Repository ទៅស្ថានភាពនៃ `<commit>` ណាមួយ។

**ឧទាហរណ៍**: ឧបមាថាអ្នកមាន Commits ដូចនេះ: `A -- B -- C -- D (HEAD)` ។
*   `git reset --soft B`: HEAD ផ្លាស់ទៅ B, C និង D នៅតែ Staged ។
*   `git reset --mixed B`: HEAD ផ្លាស់ទៅ B, C និង D នៅតែក្នុង Working Directory ប៉ុន្តែ Unstaged ។
*   `git reset --hard B`: HEAD ផ្លាស់ទៅ B, C និង D ត្រូវបានលុបទាំងស្រុងពី Working Directory និង Staging Area ។

**ការប្រុងប្រយ័ត្ន**: `git reset` ផ្លាស់ប្តូរប្រវត្តិ (Rewrites History) ។ **កុំប្រើ `git reset` លើ Commits ដែលត្រូវបាន Push ទៅ Remote Repository រួចហើយ ហើយត្រូវបានចែករំលែកជាមួយអ្នកដទៃ**។ ការធ្វើបែបនេះអាចបណ្តាលឱ្យមានបញ្ហាធ្ងន់ធ្ងរសម្រាប់អ្នកសហការផ្សេងទៀត។ វាត្រូវបានណែនាំឱ្យប្រើ `git reset` សម្រាប់តែ Local Commits ដែលមិនទាន់បាន Push ។

#### ៦.៣.២. `git revert` (Creates new history - safe)

`git revert` គឺជាវិធីសាស្ត្រសុវត្ថិភាពជាងក្នុងការបោះបង់ការផ្លាស់ប្តូរ ជាពិសេសសម្រាប់ Commits ដែលបាន Push រួចហើយ។ ជំនួសឱ្យការលុប Commits ចេញពីប្រវត្តិ `git revert` **បង្កើត Commit ថ្មីមួយ** ដែលបោះបង់ការផ្លាស់ប្តូរដែលបានធ្វើឡើងដោយ Commit ពីមុន។

#### របៀបដំណើរការ:

1.  **កំណត់ Commit ដែលត្រូវ Revert**: ស្វែងរក Hash ID របស់ Commit ដែលអ្នកចង់បោះបង់។
    ```bash
    git log --oneline
    ```
2.  **អនុវត្ត Revert**:
    ```bash
    git revert <commit-hash>
    ```
    Git នឹងបង្កើត Commit ថ្មីមួយដែលផ្ទុកនូវការផ្លាស់ប្តូរផ្ទុយពី `<commit-hash>`។ វា​នឹង​បើក Editor សម្រាប់អ្នកសរសេរសារ Commit សម្រាប់ Revert Commit ថ្មីនេះ។

**ឧទាហរណ៍**: ឧបមាថាអ្នកមាន Commits ដូចនេះ: `A -- B -- C -- D (HEAD)` ហើយអ្នកចង់បោះបង់ Commit `C` ។
*   `git revert C`

លទ្ធផល: `A -- B -- C -- D -- E (HEAD)`
*   `E` គឺជា Commit ថ្មីដែលបោះបង់ការផ្លាស់ប្តូររបស់ `C`។ Commit `C` នៅតែមាននៅក្នុងប្រវត្តិ។

#### ហេតុអ្វីត្រូវប្រើ `git revert`?

*   **មិនផ្លាស់ប្តូរប្រវត្តិ (Does not rewrite history)**: នេះជាចំណុចសំខាន់។ ដោយសារវាបង្កើត Commit ថ្មី វាមិនប៉ះពាល់ដល់ប្រវត្តិដែលមានស្រាប់ទេ។
*   **សុវត្ថិភាពសម្រាប់ការសហការ (Safe for collaboration)**: វាមានសុវត្ថិភាពក្នុងការប្រើ `git revert` លើ Commits ដែលត្រូវបាន Push ទៅ Remote Repository រួចហើយ ព្រោះវាមិនបំពានលើប្រវត្តិដែលបានចែករំលែក។
*   **អាចអនុវត្តបានច្រើនដង**: អ្នកអាច Revert Commit ណាមួយដោយមិនប៉ះពាល់ដល់ Commits ផ្សេងទៀត។

### ៦.៤. ការប្រៀបធៀប `git reset` និង `git revert`

| លក្ខណៈ             | `git reset`                                                              | `git revert`                                                                 |
| :------------------- | :----------------------------------------------------------------------- | :--------------------------------------------------------------------------- |
| **គោលបំណង**         | ផ្លាស់ទី HEAD (និង Working Dir/Staging Area អាស្រ័យលើ Mode) ទៅ Commit មួយផ្សេងទៀត។ | បង្កើត Commit ថ្មីមួយដែលបោះបង់ការផ្លាស់ប្តូររបស់ Commit ជាក់លាក់។         |
| **កែប្រែប្រវត្តិ**   | **បាទ/ចាស (Rewrites History)** - លុប Commits ចេញពីប្រវត្តិ។              | **ទេ (Does NOT rewrite History)** - បន្ថែម Commit ថ្មីទៅប្រវត្តិ។           |
| **សុវត្ថិភាពសម្រាប់ Commits ដែលបាន Push** | **គ្រោះថ្នាក់ (Dangerous)** - អាចបណ្តាលឱ្យមានបញ្ហា Merge Conflicts សម្រាប់អ្នកដទៃ។ | **សុវត្ថិភាព (Safe)** - មិនប៉ះពាល់ដល់ប្រវត្តិដែលបានចែករំលែក។            |
| **ស្ថានភាពឯកសារ**    | អាស្រ័យលើ Mode (`--soft`, `--mixed`, `--hard`) ។                       | រក្សាទុកការផ្លាស់ប្តូរនៅក្នុង Working Directory របស់អ្នកជា Staged Changes។  |
| **ករណីប្រើប្រាស់**     | បោះបង់ Local Commits ដែលមិនទាន់បាន Push, រៀបចំ Commits ឡើងវិញ។       | បោះបង់ Commits ដែលបាន Push រួចហើយ ឬ Commits នៅលើ Shared Branches។     |

**សេចក្តីសន្និដ្ឋាន**:
*   ប្រើ `git reset` (ជាពិសេស `--hard`) ដោយប្រុងប្រយ័ត្នបំផុត ហើយសម្រាប់តែ Commits ដែលមិនទាន់បាន Push ទៅ Remote Repository តែប៉ុណ្ណោះ។
*   ប្រើ `git revert` នៅពេលអ្នកចង់បោះបង់ការផ្លាស់ប្តូរនៅក្នុង Shared History (Commits ដែលបាន Push រួចហើយ)។

### ៦.៥. លំហាត់អនុវត្ត

1.  បន្តពីគម្រោង `my-git-github-project` របស់អ្នកពីជំពូកមុន។
2.  **អនុវត្ត `git stash`:**
    *   ធ្វើការផ្លាស់ប្តូរមួយចំនួននៅក្នុងឯកសារ `index.html` (ឧទាហរណ៍ បន្ថែម Paragraph ថ្មី)។
    *   បង្កើតឯកសារថ្មីមួយឈ្មោះ `temp.txt`។
    *   ប្រើ `git status` ដើម្បីមើលការផ្លាស់ប្តូរទាំងនោះ។
    *   `git stash save "Changes for a new section"` ។
    *   ប្រើ `git status` ម្តងទៀត ដើម្បីមើលថា Working Directory របស់អ្នកស្អាតហើយ។
    *   `git stash list` ដើម្បីមើល Stash របស់អ្នក។
    *   `git stash pop` ដើម្បីអនុវត្ត Stash របស់អ្នកឡើងវិញ។

3.  **អនុវត្ត `git rebase` (Local Only):**
    *   ត្រូវប្រាកដថាអ្នកនៅ Branch `main`។ `git pull origin main` ដើម្បី Update Local `main` Branch។
    *   បង្កើត Branch ថ្មីមួយឈ្មោះ `feature/rebase-demo`: `git checkout -b feature/rebase-demo` ។
    *   ធ្វើការ Commit ពីរនៅលើ `feature/rebase-demo`:
        *   `git commit -m "feat: add section 1"`
        *   `git commit -m "feat: add section 2"`
    *   ប្តូរត្រឡប់ទៅ `main` Branch: `git checkout main` ។
    *   ធ្វើការ Commit មួយនៅលើ `main` Branch: `git commit -m "refactor: improve main layout"` ។
    *   ឥឡូវនេះ `main` និង `feature/rebase-demo` បានបំបែកគ្នា។
    *   ប្តូរត្រឡប់ទៅ `feature/rebase-demo`: `git checkout feature/rebase-demo` ។
    *   អនុវត្ត `git rebase main`: `git rebase main` ។
    *   `git log --oneline --graph` ដើម្បីមើលថាប្រវត្តិ Feature Branch របស់អ្នកឥឡូវ Linear ជាមួយ `main` ហើយ។
    *   ប្តូរទៅ `main` ហើយ Merge: `git checkout main` រួច `git merge feature/rebase-demo` (វានឹងជា Fast-Forward)។
    *   លុប Branch Feature: `git branch -d feature/rebase-demo` ។

4.  **អនុវត្ត `git reset` (ដោយប្រុងប្រយ័ត្ន):**
    *   នៅលើ `main` Branch ធ្វើការ Commit ថ្មីពីរ:
        *   `git commit -m "feat: accidental commit 1"`
        *   `git commit -m "feat: accidental commit 2"`
    *   ប្រើ `git log --oneline` ដើម្បីកំណត់ Commit Hash របស់ "feat: accidental commit 1" ។
    *   **`git reset --soft`:**
        *   `git reset --soft HEAD~1` (ដើម្បីបោះបង់ Commit ចុងក្រោយ)។
        *   `git status` (អ្នកនឹងឃើញការផ្លាស់ប្តូរពី Commit ចុងក្រោយនៅតែ Staged)។
        *   `git reset --hard HEAD` (ដើម្បីសម្អាត Staged changes) ។
    *   **`git reset --mixed` (Default):**
        *   ធ្វើការ Commit ថ្មីពីរម្តងទៀត។
        *   `git reset HEAD~1` (ឬ `git reset --mixed HEAD~1`) ។
        *   `git status` (អ្នកនឹងឃើញការផ្លាស់ប្តូរ Unstaged)។
        *   `git restore .` (ដើម្បីបោះបង់ការផ្លាស់ប្តូរទាំងអស់) ។
    *   **`git reset --hard` (ប្រើដោយប្រុងប្រយ័ត្នខ្ពស់!)**:
        *   ធ្វើការ Commit ថ្មីពីរម្តងទៀត។
        *   `git reset --hard HEAD~1` (នេះនឹងលុប Commit ចុងក្រោយ និងការផ្លាស់ប្តូររបស់វាទាំងស្រុង)។
        *   `git log --oneline` ដើម្បីមើលថា Commit នោះបានបាត់ទៅហើយ។

5.  **អនុវត្ត `git revert`:**
    *   នៅលើ `main` Branch ធ្វើការ Commit ថ្មីមួយ (ឧទាហរណ៍ បន្ថែមបន្ទាត់មួយទៅ `index.html`) : `git commit -m "feat: add experimental line"` ។
    *   Push Commit នេះទៅ GitHub: `git push origin main` ។
    *   ប្រើ `git log --oneline` ដើម្បីកំណត់ Commit Hash របស់ "feat: add experimental line" ។
    *   `git revert <hash_of_experimental_commit>` ។ Git នឹងបង្កើត Revert Commit ថ្មី។
    *   `git log --oneline` ដើម្បីមើលថា Revert Commit ថ្មីត្រូវបានបន្ថែមទៅប្រវត្តិ ហើយ Commit ដើមនៅតែមាន។
    *   `git push origin main` ដើម្បី Push Revert Commit ទៅ GitHub ។

## សេចក្តីសង្ខេប៖ ភាពខុសគ្នារវាង Git និង GitHub

ដើម្បីជាការរំលឹក និងឯកសារយោងរហ័ស ខាងក្រោមនេះគឺជាតារាងប្រៀបធៀបពីភាពខុសគ្នាសំខាន់ៗរវាង Git និង GitHub:

| លក្ខណៈ               | Git                                           | GitHub                                    |
| :------------------- | :-------------------------------------------- | :---------------------------------------- |
| **ប្រភេទ**           | Distributed Version Control System (DVCS)     | Web-based Hosting Service & Collaboration Platform |
| **អ្វីជាវា**         | Software / Command-line tool                  | Online platform / Website                 |
| **គោលបំណងចម្បង**   | តាមដានការផ្លាស់ប្តូរ Code Locally ការគ្រប់គ្រង Version | Hosting Repository, Facilitating collaboration, Code review |
| **ទីកន្លែងដំណើរការ** | Locally នៅលើកុំព្យូទ័ររបស់អ្នក             | On the cloud (requires internet)          |
| **មុខងារស្នូល**    | Init, Add, Commit, Branch, Merge, Rebase, Reset, Revert | Repository hosting, Pull Requests, Issues, Code review, Project management |
| **ត្រូវការអ៊ីនធឺណិត** | មិនចាំបាច់សម្រាប់ប្រតិបត្តិការមូលដ្ឋាន       | ចាំបាច់សម្រាប់មុខងារទាំងអស់            |
| **បង្កើតដោយ**       | Linus Torvalds (2005)                         | Tom Preston-Werner et al. (2008), ក្រោយមក Microsoft |

## សេចក្តីសង្ខេប៖ ទម្រង់ការងារ (Git Workflow Patterns) ទូទៅសម្រាប់អ្នកចាប់ផ្តើមដំបូង

ការប្រើប្រាស់ Git មានទម្រង់ការងារជាច្រើន (Git Workflows) ដែលជួយសម្រួលដល់ការសហការ និងការគ្រប់គ្រង Code។ ការជ្រើសរើស Workflow ត្រឹមត្រូវអាស្រ័យលើទំហំក្រុម ភាពស្មុគស្មាញនៃគម្រោង និងគោលការណ៍អភិវឌ្ឍន៍។ ខាងក្រោមនេះគឺជាទម្រង់ការងារទូទៅមួយចំនួន:

### ១. Centralized Workflow (ទម្រង់ការងារបែបកណ្តាល)

**គំនិត**: នេះគឺជា Workflow សាមញ្ញបំផុត ដែលស្រដៀងនឹងរបៀបដែល Centralized Version Control Systems (CVCS) ដំណើរការ។ អ្នកអភិវឌ្ឍន៍ទាំងអស់ធ្វើការនៅលើ Branch មេតែមួយ (ជាធម្មតា `main` ឬ `master`)។

**របៀបដំណើរការ**:
1.  **Clone**: អ្នកអភិវឌ្ឍន៍ Clone Repository ទៅ Local។
2.  **Work**: ធ្វើការផ្លាស់ប្តូរនៅលើ `main` Branch របស់ខ្លួន។
3.  **Pull**: មុនពេល Commit និង Push ត្រូវ `git pull` ដើម្បីទាញយកការផ្លាស់ប្តូរថ្មីៗពី Remote មក Merge ជាមួយ Local Branch របស់ខ្លួន។
4.  **Push**: បន្ទាប់ពី Merge ហើយ ធ្វើការ `git push` ការផ្លាស់ប្តូរទៅ Remote Repository។

**ស័ក្តិសមសម្រាប់**: ក្រុមតូចៗ ឬគម្រោងសាមញ្ញដែលមិនមានការផ្លាស់ប្តូរ Code ច្រើនក្នុងពេលដំណាលគ្នា។

**គុណសម្បត្តិ**: សាមញ្ញ ងាយស្រួលរៀន។
**គុណវិបត្តិ**: ងាយមាន Conflict ប្រសិនបើសមាជិកក្រុមជាច្រើនធ្វើការលើឯកសារដូចគ្នាក្នុងពេលតែមួយ។

### ២. Feature Branch Workflow (ទម្រង់ការងារបែប Feature Branch)

**គំនិត**: នេះគឺជា Workflow ដែលត្រូវបានប្រើប្រាស់យ៉ាងទូលំទូលាយបំផុត។ អ្នកអភិវឌ្ឍន៍បង្កើត Branch ថ្មីមួយសម្រាប់រាល់ Feature, Bug Fix ឬ Improvement នីមួយៗ។ ការងារទាំងអស់ត្រូវបានធ្វើឡើងនៅលើ Feature Branch ដាច់ដោយឡែក។

**របៀបដំណើរការ**:
1.  **Update `main`**: ទាញយកការផ្លាស់ប្តូរចុងក្រោយពី `main` Branch (Remote) ទៅកាន់ Local `main` Branch។
2.  **Create Feature Branch**: បង្កើត Branch ថ្មីមួយពី `main` (ឧទាហរណ៍ `git checkout -b feature/login-page`)។
3.  **Work and Commit**: ធ្វើការផ្លាស់ប្តូរ និង Commit នៅលើ Feature Branch នោះ។
4.  **Push Feature Branch**: Push Feature Branch ទៅ Remote (GitHub) ។
5.  **Pull Request (PR)**: បើក Pull Request ទៅកាន់ `main` Branch ។
6.  **Review and Merge**: សមាជិកក្រុមធ្វើការ Review Code ហើយបន្ទាប់មក Merge Feature Branch ទៅក្នុង `main` ។
7.  **Delete Feature Branch**: លុប Feature Branch ចេញ។

**ស័ក្តិសមសម្រាប់**: ក្រុមទំហំមធ្យម និងធំ។

**គុណសម្បត្តិ**: ការងារដាច់ដោយឡែក ងាយស្រួល Review Code កាត់បន្ថយ Conflict នៅលើ `main` ។
**គុណវិបត្តិ**: ត្រូវការការគ្រប់គ្រង Branch បានល្អ។

### ៣. Forking Workflow (ទម្រង់ការងារបែប Forking)

**គំនិត**: Workflow នេះមានលក្ខណៈវិមជ្ឈការខ្ពស់ ហើយត្រូវបានប្រើជាទូទៅសម្រាប់គម្រោង Open Source ។ អ្នកអភិវឌ្ឍន៍ម្នាក់ៗមាន Repository ផ្ទាល់ខ្លួនរបស់ពួកគេ ដែលជា Fork នៃ Repository ផ្លូវការ។

**របៀបដំណើរការ**:
1.  **Fork**: អ្នកអភិវឌ្ឍន៍ Fork Repository ផ្លូវការទៅកាន់គណនី GitHub ផ្ទាល់ខ្លួនរបស់ពួកគេ។
2.  **Clone**: Clone Fork របស់ខ្លួនទៅ Local Computer។
3.  **Create Feature Branch**: បង្កើត Branch ថ្មីមួយនៅលើ Local Fork ។
4.  **Work and Commit**: ធ្វើការផ្លាស់ប្តូរ និង Commit ។
5.  **Push to Fork**: Push Branch ទៅ Fork របស់ខ្លួននៅលើ GitHub ។
6.  **Pull Request (PR)**: បើក Pull Request ពី Fork របស់ខ្លួនទៅកាន់ Repository ផ្លូវការ (Upstream Repository) ។
7.  **Review and Merge**: អ្នកគ្រប់គ្រង Repository ផ្លូវការ Review និង Merge PR ។

**ស័ក្តិសមសម្រាប់**: គម្រោង Open Source ឬបរិយាកាសដែលសមាជិកក្រុមមិនមានសិទ្ធិ Push ដោយផ្ទាល់ទៅ Repository ផ្លូវការ។

**គុណសម្បត្តិ**: ផ្តល់នូវភាពឯករាជ្យពេញលេញដល់អ្នកចូលរួមចំណែក បង្កើនសុវត្ថិភាព។
**គុណវិបត្តិ**: អាចស្មុគស្មាញបន្តិចសម្រាប់អ្នកចាប់ផ្តើមដំបូង ជាពិសេសក្នុងការ Sync Fork ជាមួយ Upstream ។

### ៤. Gitflow Workflow (ទម្រង់ការងារបែប Gitflow) - កម្រិតខ្ពស់

**គំនិត**: នេះគឺជា Workflow ដែលមានរចនាសម្ព័ន្ធខ្ពស់ និងស្មុគស្មាញ ដែលត្រូវបានរចនាឡើងសម្រាប់ការអភិវឌ្ឍន៍ដែលមានលក្ខណៈជា Version Release។ វារួមបញ្ចូលនូវ Branch រយៈពេលវែងពីរ (`main` និង `develop`) រួមជាមួយនឹង Branch រយៈពេលខ្លីសម្រាប់ Features, Releases, និង Hotfixes ។

**ស័ក្តិសមសម្រាប់**: គម្រោងធំៗដែលមាន Release Cycle ទៀងទាត់ និងតម្រូវការ Versioning ជាក់លាក់។

**ចំណាំ**: សម្រាប់អ្នកចាប់ផ្តើមដំបូង **Feature Branch Workflow** ជាធម្មតាគឺជាជម្រើសដ៏ល្អបំផុតដើម្បីចាប់ផ្តើម។
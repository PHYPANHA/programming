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

# ជំពូកទី ៧៖ ការកំណត់រចនាសម្ព័ន្ធ (Configuration)

នៅក្នុងការអភិវឌ្ឍន៍កម្មវិធី ជារឿយៗយើងត្រូវគ្រប់គ្រង Configuration (ការកំណត់រចនាសម្ព័ន្ធ) ដូចជា Database Connection Strings, API Endpoints, Environment Variables, ឬ Log Levels ។ ការដាក់ Configuration ទាំងនេះដោយផ្ទាល់នៅក្នុង Image របស់ Container អាចបង្កបញ្ហាដូចជាការបង្កើត Image ថ្មីរាល់ពេលដែល Configuration ផ្លាស់ប្តូរ ឬអាចធ្វើឱ្យទិន្នន័យសម្ងាត់ត្រូវបានលាតត្រដាង។

Kubernetes ផ្តល់នូវ Objects ពីរដើម្បីដោះស្រាយបញ្ហានេះ៖ **ConfigMaps** សម្រាប់ទិន្នន័យ Configuration ដែលមិនមែនជាទិន្នន័យសម្ងាត់ និង **Secrets** សម្រាប់ទិន្នន័យសម្ងាត់។
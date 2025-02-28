export default function Logo(props: { className?: string, style?: React.CSSProperties }) {
  const { className, style } = props

  return (
    <span className={`type-song select-none ${className}`} style={style}>
      <span className="text-[1.5em]">培</span>
      <span>养</span>
      <span className="inline-block -translate-y-[10%]">计</span>
      <span>划</span>
    </span>
  )
}
